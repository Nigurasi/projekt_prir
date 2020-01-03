#include "inversion.h"

void printM(int* a, uint size)
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

void computeAdjugateMatrix(int* a, int* adjugate, uint size)
{
    if (size == 1)
    {
	adjugate[0] = 1;
    }
    else
    {
	int minor[(size-1) * (size-1)], sign = 1;

	for(uint i = 0; i < size; ++i)
	{
	    for(uint j = 0; j < size; ++j)
	    {
		initializeMinor(a, minor, size, i, j);
		sign = ((i + j) % 2 == 0) ? 1 : -1;

		adjugate[j * size + i] = sign * determinant(minor, size-1);
	    }
	}
    }
}

bool inverseMatrix(int* a, float* inverse, uint size)
{
    int det = determinant(a, size);
    if(det == 0)
    {
        printf("Determinant equals 0. Unable to inverse a matrix\n");
        return false;
    }
    else
    {
	int adjugateMatrix[size * size];
	computeAdjugateMatrix(a, adjugateMatrix, size);

	for(uint i = 0; i < size; ++i)
	{
	    for(uint j = 0; j < size; ++j)
	    {
		inverse[i * size + j] = ((float)adjugateMatrix[i * size + j])/det;
	    }
	}

	return true;
    }
}

