#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <limits.h>
#include "grid_type.h"

#define INF SHRT_MAX*3
#define ROOT 0
#define FALSE 0
#define TRUE 1

//Declaraçoes de funçoes
int is_valid(int p, int n);
void init_grid(GRID_T* grid);
void alloc_matrix(int ***matrix, int n);
void input_matrix(int **matrix, int n);
void split_matrix(int** matrix, GRID_T* grid, int** m, int n);
int** copy_matrix(int** matrix, int n2);
void fill_matrix(int** matrix, int val, int n);
void fox_algorithm(int** matrix_A, int** matrix_B, int** matrix_C, GRID_T* grid, int n2);
void min_plus_alg(int** matrix_A, int** matrix_B, int** matrix_C, int n);
int min(int v1, int v2);
void free_matrix(int** matrix, int n);
void print_matrix(int** matrix, int n);

//Main
int main(int argc, char *argv[]){
    
    int n, p, rank, flag=FALSE;
    GRID_T grid;
    int **matrix;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);


    //So o processador ROOT pode manipular inputs
    if(rank == ROOT){
        scanf("%d", &n);
        flag = is_valid(p, n);
    }
    
    
    MPI_Bcast(&flag, 1, MPI_INT, ROOT, MPI_COMM_WORLD);
    
    if(!flag){
        if(rank == ROOT)
            printf("ERROR: Invalid configuration!\n");
        
        MPI_Finalize();
        return 0;
    }
    

    init_grid(&grid);

    MPI_Bcast(&n, 1, MPI_INT, ROOT, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    
    
    alloc_matrix(&matrix, n);

    

    if(rank == ROOT) {
        input_matrix(matrix, n);
    }

    //MPI_Barrier(MPI_COMM_WORLD);
    MPI_Bcast(&(matrix[0][0]), n*n, MPI_INT, ROOT, MPI_COMM_WORLD);

    

    int n2 = n/2;

    int **matrix_A, **matrix_B, **matrix_C; 
    
    alloc_matrix(&matrix_A, n2);
    alloc_matrix(&matrix_B, n2);
    alloc_matrix(&matrix_C, n2);

    

    split_matrix(matrix, &grid, matrix_A, n2);

    

    matrix_B = copy_matrix(matrix_A, n2);

    

    fill_matrix(matrix_C, INF, n2);

    

    MPI_Barrier(MPI_COMM_WORLD);
    
    double start = MPI_Wtime();

    for(int step=1; step<n-1; step*=2){

        fox_algorithm(matrix_A, matrix_B, matrix_C, &grid, n2);

        matrix_A = copy_matrix(matrix_C, n2);
        matrix_B = copy_matrix(matrix_C, n2);
    

    }
    
    int** res_m;
    alloc_matrix(&res_m, n2);

    //Processos nao raiz vao enviar resultado para o processo ROOT
    if(rank != ROOT) {
        MPI_Send(&matrix_C[0][0], n2*n2, MPI_INT, ROOT, 0, MPI_COMM_WORLD);
    }
    
    else {
        for(int i=0; i<n2; i++){
            for(int j=0; j<n2; j++){
                if(matrix_C[i][j] == INF){
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] = matrix_C[i][j];
                }
            }
        }
        
        for(int i=1; i<p; i++){
            MPI_Recv(&res_m[0][0], n2*n2, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            int row = i/grid.q;
            int col = i%grid.q;

            for(int j=0; j<n2; j++) {
                for(int k=0; k<n2; k++){
                    if(res_m[j][k] == INF){
                        matrix[row*n2+j][col*n2+k] = 0;
                    }
                    else{
                        matrix[row*n2+j][col*n2+k] = res_m[j][k];
                    }
                }
            }
        }
        
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double finish = MPI_Wtime();

    if(rank == ROOT){
        print_matrix(matrix, n);
        printf("Execution time: %.5lf\n", (finish-start));
    }

    free_matrix(matrix_A, n2);
    free_matrix(matrix_B, n2);
    free_matrix(matrix, n);
    free_matrix(matrix_C, n2);
    free_matrix(res_m, n);
    

    MPI_Finalize();

    return 0;
}

//Verifica se o algoritmo pode ser aplicado
int is_valid(int p, int n){
    return (n%(int)sqrt(p) != 0 || floor(sqrt(p)) != (int)sqrt(p)) ? FALSE : TRUE;
}

//Criaçao da grid
void init_grid(GRID_T* grid) {
    int rank, dim[2], per[2], coord_A[2], coord_B[2];

    MPI_Comm_size(MPI_COMM_WORLD, &(grid->procs));

    grid->q = (int)sqrt(grid->procs);

    dim[0] = dim[1] = grid->q;
    per[0] = per[1] = 1;

    MPI_Cart_create(MPI_COMM_WORLD, 2, dim, per, 1, &(grid->comm));

    MPI_Comm_rank(grid->comm, &(grid->rank));

    MPI_Cart_coords(grid->comm, grid->rank, 2, coord_A);

    grid->row = coord_A[0];
    grid->col = coord_A[1];

    //ROW_COMM_WORLD
    coord_B[0] = 0;
    coord_B[1] = 1;

    MPI_Cart_sub(grid->comm, coord_B, &(grid->rows));

    //COL_COMM_WORLD
    coord_B[0] = 1;
    coord_B[1] = 0;

    MPI_Cart_sub(grid->comm, coord_B, &(grid->cols));

}

//Aloca matrix em memoria e inicializa valores a zeros
void alloc_matrix(int ***matrix, int n){
    
    int *p = (int*)malloc(n*n*sizeof(int*));
    //printf("ALLC 1\n");
    (*matrix) = (int**)malloc(n*sizeof(int*));
    //printf("ALLC 2\n");
    for(int i=0; i<n; i++){
        (*matrix)[i] = &(p[i*n]);
    }
    //printf("ALLC 3\n"); 
    
}

//Input da matrix
void input_matrix(int **matrix, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);

            if( i!=j && matrix[i][j] == 0){
                matrix[i][j] = INF;
            }
        }
    }
}

//Cria uma submatriz de uma principal
void split_matrix(int** matrix, GRID_T* grid, int** m, int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[i][j] = matrix[grid->row*n+i][grid->col*n+j];
        }
    }
}

//cria uma copia exata para outra matriz
int** copy_matrix(int** matrix, int n){
    int** aux_m; 
    alloc_matrix(&aux_m, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            aux_m[i][j] = matrix[i][j];
        }
    }
    return aux_m;
}

//Preenche a matriz com um ceto valor
void fill_matrix(int** matrix, int val, int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = val;
        }
    }
}

//Algoritmo FOX
void fox_algorithm(int** matrix_A, int** matrix_B, int** matrix_C, GRID_T* grid, int n2) {
    int o = (grid->row+1) % grid->q;
    int d = (grid->row + grid->q-1) % grid->q;

    int** aux_m;
    alloc_matrix(&aux_m, n2);

    for(int i=0; i<grid->q; i++){
        int root = (grid->row+i) % grid->q;
        
        if(root == grid->col){
            MPI_Bcast(&matrix_A[0][0], n2*n2, MPI_INT, root, grid->rows);
            min_plus_alg(matrix_A, matrix_B, matrix_C, n2);
        }
        else {
            MPI_Bcast(&aux_m[0][0], n2*n2, MPI_INT, root, grid->rows);
            min_plus_alg(aux_m, matrix_B, matrix_C, n2);
        }

        MPI_Send(&matrix_B[0][0], n2*n2, MPI_INT, d, 0, grid->cols);

        MPI_Recv(&matrix_B[0][0], n2*n2, MPI_INT, o, 0, grid->cols, MPI_STATUS_IGNORE);

        //MPI_Sendrecv(&matrix_B[0][0], n2*n2, MPI_INT, d, 0, &matrix_B[0][0], n2*n2, MPI_INT, o, 0, grid->cols, MPI_STATUS_IGNORE);
    } 
}

//Algoritmo de Min_plus
void min_plus_alg(int** matrix_A, int** matrix_B, int** matrix_C, int n){
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                matrix_C[i][j] = min(matrix_C[i][j], (matrix_A[i][k] + matrix_B[k][j]));
            }
        }
    }
}

//Calculo do valor minimo
int min(int v1, int v2){
    return v1<v2 ? v1 : v2;
}

//Liberta da memoria a matriz
void free_matrix(int** matrix, int n) {
    free(*matrix);
    free(matrix);
}

//Imprime a matriz
void print_matrix(int** matrix, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}