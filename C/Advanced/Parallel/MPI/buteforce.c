#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define MY_TAG 0
#define ROOT 0

int main(int argc, char *argv[]) {
  int length;
  char input[length];

  int my_rank;
  int n_proc;

  printf("Enter you length of code: ");
  scanf("%d", &length);


  printf("Enter you code(10 digits): ");
  scanf("%s", input);

  //Init the MPI
  MPI_Init(&argc, &argv);
  MPI_Status status;
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &n_proc);

  char guess[length];
  int flag = 0;

  //ROOT
  if (my_rank == 0){
      clock_t startClock = clock();
      while(1){
        flag = 0;
        MPI_Bcast(&flag, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(guess, length, MPI_CHAR, guess, length, MPI_CHAR, ROOT, MPI_COMM_WORLD);

        for(int i=0; i<length/n_proc; i++){
          int x = rand()%10;
          guess[i] = x + '0';
        }

        MPI_Gather(guess, length, MPI_CHAR, guess, length, MPI_CHAR, ROOT, MPI_COMM_WORLD);
        for(int i=0; i<length; i++){
          if(guess[i] != input[i]){
            flag = 1;
          }
        }

        if(!flag) {
          printf("Code was chracked!!\n");
          break;
        }

      }
      clock_t finishClock = clock();
      printf("%ld", (finishClock - startClock) / CLOCKS_PER_SEC);
  }
  else {
    for(int i=0; i<length/n_proc; i++){
      int x = rand()%10;
      guess[i] = x + '0';
    }
  }
  return 0;
}
