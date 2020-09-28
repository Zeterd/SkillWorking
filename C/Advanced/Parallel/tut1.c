#include <stdio.h>
#include <mpi.h>

int main(int argc, char const *argv[])
{
	int rank;
	int size;

	//Inicializa o programa a executar em paralelo
	MPI_Init(&argc, &argv);

	//Retorna o rank do processador a executar o programa no comunicador MPI_COMM_WORLD
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	//Retorna o numero de processadores a executarem o programa no comunicador MPI_COMM_WORLD
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("Hello world from process %d of %d\n", rank, size);

	//Termina o paralelismo
	MPI_Finalize();

	return 0;
}