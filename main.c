/*
 * Macierz odwrotna - Metoda dopelnien algebraicznych
*/
#include "inversion.h"

void printMatrix(int* a)
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
	    a[i * N + j] = j+1;//rand()%10;
	}
    }
}

int main() 
{
    srand(time(NULL));
    int A[N * N];
    initializeMatrix(A);
    printMatrix(A);

    inverseMatrix(A);
    printMatrix(A);

    return 0;
}
