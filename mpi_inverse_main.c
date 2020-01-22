#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define send_tag 2001
#define rcv_tag 2002

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

void initializeMinor(int* source, int* minor, uint size, uint row, uint column)
{
    for (uint i = 0; i < size; ++i)
    {
        if (i != row)
        {
            for (uint j = 0; j < size; ++j)
            {
                if (j == column)
                    continue;
                else if (j < column)
                {
                    if (i < row)
                    {
                        minor[i * (size - 1) + j] = source[i * size + j];
                    }
                    else
                    {
                        minor[(i - 1) * (size - 1) + j] = source[i * size + j];
                    }
                }
                else
                {
                    if (i < row)
                    {
                        minor[i * (size - 1) + j - 1] = source[i * size + j];
                    }
                    else
                    {
                        minor[(i - 1) * (size - 1) + j - 1] = source[i * size + j];
                    }
                }
            }
        }
    }
}

int determinant(int* a, uint size)
{
    if(size == 1)
    {
        return a[0];
    }
    else
    {
        int sum = 0, sign = -1;

        for(uint i = 0; i < size; ++i)
        {
            int minor[(size-1) * (size-1)];
            initializeMinor(a, minor, size, 0, i);

            sign = (i % 2) ? -1 : 1;
            sum += sign * a[0 * size + i] * determinant(minor, size-1);
        }

        return sum;
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
    int s_val, e_val;
    
    error = MPI_Init(&argc, &argv);
    root_id = 0;

    error = MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    error = MPI_Comm_size(MPI_COMM_WORLD, &processes);

    if (processes < N * N)// || processes == N*N)
    {
	if (process_id == root_id)
        {
            printf("[root process] Started run for %d processes.\n", processes);

	    uint avg_val = (N * N)/processes;

            initializeMatrix(A);
            printf("Matrix:\n");
            printMatrixInt(A);

            int det = determinant(A, N);
            if (det == 0)
            {
                printf("Determinant equals 0. Unable to inverse a matrix.\n");
                return 0;
            } else 
            {
		for (uint i = 1; i < processes; ++i)
		{
		    s_val = i * avg_val + 1;
		    e_val = (i + 1) * avg_val;

		    if ((N * N - e_val) < avg_val)
			e_val = N * N - 1;

		    int num_vals = e_val - s_val + 1;
		    error = MPI_Send(&num_vals, 1, MPI_INT, i, send_tag, MPI_COMM_WORLD);

		    //error = MPI_Send();
		}
	    }
        }
        else
        {
	    int num_vals = 0;
            error = MPI_Recv(&num_vals, 1, MPI_INT, root_id, send_tag, MPI_COMM_WORLD, &status);
	    printf("[process no. %d] Received %d values.\n", process_id, num_vals);
        }
	error = MPI_Finalize();

    	return 0;
    }
    else
    {
	printf("Incorrect number of processes.\n");
	return 0;
    }
}
