#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

#define N 10
typedef unsigned int uint;

void printMatrixInt(int* a)
{
    for(uint i = 0; i < N; ++i)
    {
	for(uint j = 0; j < N; ++j)
	{
	    printf("%d ", a[i * N + j]);
	}
	printf("\n");
    }
}

void initializeMatrix(int* a)
{
    for(uint i = 0; i < N; ++i)
    {
	for(uint j = 0; j < N; ++j)
	{
	    a[i * N + j] = rand()%10;
	}
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));

    int A[N * N];
    float inverseMatrix[N * N];

    MPI_Status status;
    int process_id, root_id, processes;
    int error;
    
    error = MPI_Init(&argc, &argv);
    root_id = 0;

    error = MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    error = MPI_Comm_size(MPI_COMM_WORLD, &processes);

    if (process_id == root_id)
    {
	printf("I'm root process.\n");

        initializeMatrix(A);
	printf("Matrix:\n");
	printMatrixInt(A);
    }
    else
    {
	printf("I'm not root process :(\n");
    }
    error = MPI_Finalize();

    return 0;
}
