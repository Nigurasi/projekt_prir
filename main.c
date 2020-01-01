/*
 * Macierz odwrotna - Metoda dopelnien algebraicznych
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2

typedef unsigned int uint;

void printMatrix(int a[N][N])
{
    for(uint i = 0; i < N; ++i)
    {
	for(uint j = 0; j < N; ++j)
	{
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
}

void initializeMatrix(int a[N][N])
{
    for(uint i = 0; i < N; ++i)
    {
	for(uint j = 0; j < N; ++j)
	{
	    a[i][j] = rand()%100;
	}
    }
}

//TODO: void initializeMinor(int source[N][N], int minor[][], uint row, uint column)

int determinant(int a[N][N], uint n)
{
    if(n == 1)
    {
	return a[0][0];
    }
    else
    {
	int sum = 0, sign = 1;

	for(uint i = 0; i < n; ++i)
	{
	    int minor[n-1][n-1];
//	    initializeMinor(a, minor, 0, i);

	    sign = (i % 2) ? -1 : 1;
	    sum += sign * a[0][i] * determinant(minor, n-1);
	}

	return sum;
    }
}

void inverseMatrix(int a[N][N])
{
    int det = determinant(a, N);
    printf("Determinant equals %d\n", det);
    if(det == 0)
    {
	printf("Determinant equals 0. Unable to inverse a matrix\n");
	return;
    }
    else 
    {
	return;
    }
}

int main() 
{
    srand(time(NULL));
    int A[N][N];
    initializeMatrix(A);
    printMatrix(A);

    inverseMatrix(A);
    printMatrix(A);

    return 0;
}
