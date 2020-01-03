/*
 * Macierz odwrotna - Metoda dopelnien algebraicznych
*/
#include "inversion.h"
#define N 4

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
    initializeMatrix(A);
    printMatrixInt(A);

    inverseMatrix(A, inverse);
    printMatrixFloat(inverse);

    return 0;
}
