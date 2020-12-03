#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <limits.h>

#define INF INT_MAX
#define ROOT 0

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

//Allocate matix in memory with garbage values
int** alloc_matrix(int dim) {
    int *mat = (int*) malloc(dim*dim*sizeof(int));

    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            *(mat+i*dim+j) = 0;
        }
    }

    return mat;
}




int** init_matrix(int **matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        
            if(matrix[i][j] == 0 && i != j){
                matrix[i][j] = INF;
            }
        
        }
    }

    return matrix;
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

void sub_matrix(int** matrix, GRID_T* grid, MATRIX* m){
    for(int i=0; i<m->dim; i++){
        for(int j=0; j<m->dim; j++){
            int index_i = grid->row*m->dim+i;
            int index_j = grid->col*m->dim+j;
            m->entries[i][j] = matrix[index_i][index_j];
        }
    }
}

void fill_Mat(MATRIX* m, int value){
    for(int i=0; i<m->dim; i++){
        for(int j=0; j<m->dim; j++){
            m->entries[i][j] = value;
        }
    }
}

void min_plus(MATRIX* mA, MATRIX* mB, MATRIX* mC){
    for(int i=0; i<mA->dim; i++){
        for(int j=0; j<mA->dim; j++){
            for(int k=0; k<mB->dim; k++){
                mC->entries[i][j] = min(mC->entries[i][j], ( mA->entries[i][k] + mB->entries[k][j] ));
            }
        }
    }
}

void copy_mat(MATRIX* m1, MATRIX* m2, int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            m1->entries[i][j] = m2->entries[i][j];
        }
    }
}

int valid(int np, int dim){
    return (dim%(int)sqrt(np) != 0 || floor(sqrt(np)) != (int)sqrt(np)) ? 1 : 0;
}

void main(int argc, char *argv[]){
    int** matrix;
    int rank, np, n, flag=0;
    GRID_T grid;
    MPI_Status status;

    MPI_Init(&argc, &argv);    

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    if(rank == ROOT){
        scanf("%d", &n);
        flag = valid(np, n);
    }

    MPI_Bcast(&flag, 1, MPI_INT, ROOT, MPI_COMM_WORLD);

    if(flag){
        printf("Parameters don't support algorithm!! ABORTING...");
        MPI_Finalize();
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    create_grid(&grid);

    matrix = alloc_matrix(n);

    if(rank == ROOT){
        matrix = init_matrix(matrix, n);
    }

    MPI_Bcast(&(matrix), n*n, MPI_INT, 0, MPI_COMM_WORLD);

    int dim2 = n/2;

    MATRIX* matA = new_MATRIX(dim2);
    MATRIX* matB = new_MATRIX(dim2);
    MATRIX* matC = new_MATRIX(dim2);

    sub_matrix(&grid, matrix, matA);

    copy_mat(matB->entries, matA->entries, dim2);

    fill_Mat(&matC, INF);

    for(int i=1; i<n-1; i*=2){
        fox_algorithm(&grid, matA, matB, matC, n);

        copy_mat(matA->entries, matC->entries, dim2);
        copy_mat(matB->entries, matC->entries, dim2);
    }

    





    free(*matrix);
    free(matrix);

    MPI_Finalize();
}
