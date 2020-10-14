#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <string.h>

#define ROOT 0

void main(int argc, char *argv[]) {
  int my_rank;
  int n_proc;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &n_proc);

  char msg[30];

  if(my_rank != ROOT){
      sprintf(msg, "Hello from the other side");
      MPI_Send(msg, strlen(msg)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
  }
  else {
    printf("It's processor 0 and i'm listening...\n");
    for(int i=1; i<n_proc; i++){
      MPI_Recv(msg, 30, MPI_CHAR, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      printf("Processor: %d Sended: %s \n", i, msg);
    }

  }

  MPI_Finalize();

}
