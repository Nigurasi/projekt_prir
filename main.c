/*
 * Macierz odwrotna - Metoda dopelnien algebraicznych
*/
#include "inversion.h"
#include <unistd.h>
#define N 11

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

void printMatrixFloat(float* a)
{
    for(uint i = 0; i < N; ++i)
    {
        for(uint j = 0; j < N; ++j)
        {
            printf("%.3f ", a[i * N + j]);
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

int main() 
{
    srand(time(NULL));
    int A[N * N];
    float inverse[N * N];
    float inverseOpenMP[N*N];
    initializeMatrix(A);
    printf("Matrix:\n");
    printMatrixInt(A);

    printf("Measuring sequential solution...\n");
    clock_t time;
    time = clock();
    inverseMatrix(A, inverse, N);
    time = clock() - time;
    printf("Sequential inversion:\n");
    printMatrixFloat(inverse);

    sleep(1);

    printf("Measuring parallel solution...\n");
    clock_t timeOpenMP;
    timeOpenMP = clock();
    inverseMatrixOpenMP(A, inverseOpenMP, N);
    timeOpenMP = clock() - timeOpenMP;
    printf("Parallel inversion:\n");
    printMatrixFloat(inverseOpenMP);

    float measuredTime = ((float)time)/(CLOCKS_PER_SEC / 1000);
    float measuredTimeOpenMP = ((float)timeOpenMP)/(CLOCKS_PER_SEC / 1000);
    printf("\nSequential inversion took %.3f miliseconds to execute.\n", measuredTime);
    printf("Parallel inversion took %.3f miliseconds to execute.\n", measuredTimeOpenMP);
    printf("Difference(seq - OpenMP): %.3f ms\n", measuredTime - measuredTimeOpenMP);

    return 0;
}
