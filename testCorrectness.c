/*
 * [TEST] Macierz odwrotna - Metoda dopelnien algebraicznych
*/
#include "inversion.h"

bool FloatEquals(float a, float b)
{
    return fabs(a - b) < EPS;
}

void printMatrixInt(int* a, uint size)
{
    for(uint i = 0; i < size; ++i)
    {
	for(uint j = 0; j < size; ++j)
	{
	    printf("%d ", a[i * size + j]);
	}
	printf("\n");
    }
}

void printMatrixFloat(float* a, uint size)
{
    for(uint i = 0; i < size; ++i)
    {
        for(uint j = 0; j < size; ++j)
        {
            printf("%.3f ", a[i * size + j]);
        }
        printf("\n");
    }
}

void compareInverse(float* ref, float* calc, uint size)
{
    uint incorrect = 0;
    for(uint i = 0; i < size; ++i)
    {
	for(uint j = 0; j < size; ++j)
	{
	    uint index = i * size + j;
	    if(!FloatEquals(ref[index], calc[index]))
	    {
	        printf("Miscompare at i = %d j = %d -- ref = %.3f calc = %.3f\n", i, j, ref[index], calc[index]);
		incorrect++;
	    }
	}
    }
    if(incorrect == 0)
	printf("Everything's OK\n\n");
}

int main() 
{
    printf("TEST 1\n");
    int A[2 * 2] = { 
	    1, 2, 
	    3, 4
    };
    float inverse[2 * 2];
    float refInverse[2 * 2] = {
    	-2.0, 1.0,
	1.5, -0.5
    };
    inverseMatrix(A, inverse, 2);
    compareInverse(refInverse, inverse, 2);

    printf("TEST 2\n");
    
    int B[3 * 3] = {
        1, 2, 3, 
        4, 5, 6,
	7, 8, 9
    };
    float inverseB[3 * 3];
    if (inverseMatrix(B, inverseB, 3))
	printf("[ERROR]Inverse matrix was calculated but it shouldn't.\n");
    else
	printf("Everything's OK\n\n");

    return 0;
}
