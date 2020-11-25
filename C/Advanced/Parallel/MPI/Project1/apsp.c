#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define INF 99999 //MUDAR!!

//Declaraçoes de funçoes
int min(int v1, int v2);
void printMatrix(int** m, int mSize);
int **matrix_sum(int **m1, int **m2, int mSize);

//Calculo do algoritmo
int **matrix_sum(int **m1, int **m2, int mSize){
    int **matrix = malloc(sizeof(int*)*mSize);

    for(int i=0; i<mSize; i++){
        matrix[i] = (int*)malloc(sizeof(int*)*mSize);
    }

    for(int i=0; i<mSize; i++){
        for(int j=0; j<mSize; j++){
            
            matrix[i][j] = INF;

            for(int k=0; k<mSize; k++){
                matrix[i][j] = min(matrix[i][j], (m1[i][k]+m2[k][j]) );
            }
        }
    }
    return matrix;
}

//Retorna minimo valor
int min(int v1, int v2){return ((v1 < v2) ? v1 : v2);}


void printMatrix(int** m, int mSize){

    for(int i=0; i<mSize; i++){
        for(int j=0; j<mSize; j++){
            if(m[i][j] == INF)
                m[i][j] = 0;

            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}


int main(){
    int matSize = 0;
    
    clock_t start, finish;

    scanf("%d", &matSize);

    //Ciar a grid em formato matrix n*n
    int** matrix = malloc(matSize*sizeof(int*));
    
    for(int i=0; i<matSize; i++){
        //Criar para cada i da grid um array de tamanho n
        matrix[i] = (int*)malloc(sizeof(int*) * matSize);
    }

    //input da matriz
    for(int i=0; i<matSize; i++){
        for(int j=0; j<matSize; j++){
            
            scanf("%d", &matrix[i][j]);
            
            if(matrix[i][j]==0 && j!=i)
                matrix[i][j] = INF;    
        }
    }
    

    int f=1;;
    int **newMat = matrix;

    start = clock();

    //Executar algoritmo
    while (f < matSize){
        newMat = matrix_sum(newMat, newMat, matSize);
        f*=2;
    }

    finish = clock();

    //Imprimir matriz final
    printMatrix(newMat, matSize);
    double t = (finish-start);
    printf("Tempo de execuçao: %.2f segundos.", t/CLOCKS_PER_SEC);

    free(newMat);

    return 0;

}