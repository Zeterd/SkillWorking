#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define INF 9999

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

int main(int argc, char *argv[]){
    
    //Input
    int n, rank, np;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);    

    //TESTE!!
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    if(np != 4) {printf("Execuçao com 4 processadores!!\n");return -1;}

    if(rank == 0){
        scanf("%d", &n);
        
        int **matrix = input_matrix(n);

        for(int i=1; i<np; i++){
            MPI_Send(matrix[i], n*sizeof(int*), MPI_INT, i, 0,MPI_COMM_WORLD);
        }
        printf("Hey1\n");
        for(int i=0; i<n; i++){
            matrix[i] = matrix[i] + 10;
        }
        printf("Hey2\n");
        for(int i=1; i<np; i++)
            MPI_Recv(matrix[i], n*sizeof(int*), MPI_INT, i, 0, MPI_COMM_WORLD, &status);

        print_matrix(matrix, n);

    }
    else {
        int *m = (int*)malloc(sizeof(int*)*n);

        MPI_Recv(m, n*sizeof(int*), MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Hey3\n");
        for(int i=0; i<n; i++){
           m[i] = m[i] + 10 ;
        }

        MPI_Send(m, n*sizeof(int*), MPI_INT, 0, 0,MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
