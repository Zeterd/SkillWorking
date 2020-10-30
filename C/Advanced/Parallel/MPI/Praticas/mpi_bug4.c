#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main(int argc, char *argv[]) {
  int numprocs, rank, tag, src, dest, i;
  float a[SIZE][SIZE] = { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,
                          9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 };
  float b[SIZE];
  MPI_Datatype rowtype;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

 if (numprocs != SIZE) {
    MPI_Finalize();
    if (rank == 0)
      printf("Run the program with %d processes!\n", SIZE);
    exit(0);
  }

  printf("Proc %d starting...\n", rank);
  tag = 0;
  src = 0;

  MPI_Type_contiguous(SIZE, MPI_FLOAT, &rowtype);
  MPI_Type_commit(&rowtype);

  if (rank == 0) {   
    for (i = 0; i < numprocs; i++)
      MPI_Send(&a[i][0], 1, rowtype, i, tag, MPI_COMM_WORLD);
  }
  MPI_Recv(b, SIZE, rowtype, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  printf("Proc %d received b = %3.1f %3.1f %3.1f %3.1f\n", rank, b[0], b[1], b[2], b[3]);

  MPI_Type_free(&rowtype);
  MPI_Finalize();
}

/*

  PROBLEMA: Processadores != 0 nao sabiam o que era o rowtype, ou seja, nao tava inicializado
  CORREÇAO: Meter o MPI_Type_* para fora do rank 0 para que todos soubessem o que era o tipo rowtype

*/