#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

void printMatrix(int a[N][N])
{
    for(int i = 0; i < N; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
}

void initializeMatrix(int a[N][N])
{
    for(int i = 0; i < N; ++i)
    {
	for(int j = 0; j < N; ++j)
	{
	    a[i][j] = rand()%100;
	}
    }
}

void inverseMatrix(int a[N][N])
{
}

int main() 
{
    srand(time(NULL));
    int A[N][N];
    initializeMatrix(A);
    printMatrix(A);

    return 0;
}
