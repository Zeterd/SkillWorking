#include <mpi.h>

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