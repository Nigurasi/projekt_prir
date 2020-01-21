#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    MPI_Status status;
    int process_id, root_id, processes;
    int error;
    
    error = MPI_Init(&argc, &argv);
    root_id = 0;

    error = MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    error = MPI_Comm_size(MPI_COMM_WORLD, &processes);

    if (process_id == root_process)
    {
	printf("I'm root process.\n");
    }
    else
    {
	printf("I'm not root process :(\n");
    }
    error = MPI_Finalize();

    return 0;
}
