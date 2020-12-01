#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define INF 9999

typedef struct {
    MPI_Comm comm;
    MPI_Comm rows;
    MPI_Comm cols;
    int procs;
    int row;
    int col;
    int rank;
    int q;
}GRID_T;

typedef struct {
    int dim;
    int **entries;
}MATRIX;

int** input_matrix(int n){

    int **matrix = malloc(sizeof(int)*n);

    for(int i=0; i<n; i++){
        matrix[i] = (int*)malloc(sizeof(int*)*n);
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}
void print_matrix(int** matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void create_grid(GRID_T* grid){
    int rank, dim[2], per[2], coord[2], coord2[2];

    //MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &(grid->procs));
    
    grid->q = (int)sqrt(grid->procs);

    dim[0] = grid->q;
    dim[1] = grid->q;

    per[0] = 1;
    per[1] = 1;

    MPI_Cart_create(MPI_COMM_WORLD, 2, dim, per, 1, &(grid->comm));
    MPI_Comm_rank(grid->comm, &(grid->rank));

    MPI_Cart_coords(grid->comm, grid->rank, 2, coord);

    grid->row = coord[0];
    grid->col = coord[1];

    //ROW_COMM_WORLD
    coord2[0] = 0;
    coord2[1] = 1;

    MPI_Cart_sub(grid->comm, coord2, &(grid->rows));

    //COL_COMM_WORLD
    coord2[0] = 1;
    coord2[1] = 0;

    MPI_Cart_sub(grid->comm, coord2, &(grid->cols));
}

void fox_algth(GRID_T* grid, int dim, MATRIX* mA, MATRIX* mB, MATRIX* mC){
    int org, dest, root;

    MATRIX* tmp;

    int half_dim = dim/grid->q;
    mC = all_zeros(); //TODO

    org = (grid->row + 1) % grid->q;
    dest = (grid->row + grid->q - 1) % grid->q;

    tmp = alloc_matrix(half_dim); //TODO

    for(int i=0; i<grid->q; i++){
        root = (grid->row + i) % grid->q;
        if(root == grid->col){
            //MPI_BCAST
            //TODO THE DERIVATED MATRIX TYPE
        }
    }

}


int main(int argc, char *argv[]){
    
    //Input
    int n, rank, np;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);    

    //TESTE!!
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    if(rank == 0){
        scanf("%d", &n);
        
        int **matrix = input_matrix(n);

        for(int i=1; i<np; i++){
            MPI_Send(matrix[i], n, MPI_INT, i, 0,MPI_COMM_WORLD);
        }
        printf("Hey1\n");
        for(int i=0; i<n; i++){
            matrix[i] = matrix[i] + 10;
        }
        printf("Hey2\n");
        for(int i=1; i<np; i++)
            MPI_Recv(matrix[i], n, MPI_INT, i, 0, MPI_COMM_WORLD, &status);

        print_matrix(matrix, n);

    }
    else {
        int *m = (int*)malloc(sizeof(int*)*n);

        MPI_Recv(m, n, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Hey3\n");
        for(int i=0; i<n; i++){
           m[i] = m[i] + 10 ;
        }

        MPI_Send(m, n, MPI_INT, 0, 0,MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
