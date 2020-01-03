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

void initializeMinor(int* source, int* minor, uint n, uint row, uint column)
{
    for (uint i = 0; i < n; ++i)
    {
        if (i != row)
        {
            for (uint j = 0; j < n; ++j)
            {
                if (j == column)
                    continue;
                else if (j < column)
                {
                    if (i < row)
                    {
                        minor[i * (n - 1) + j] = source[i * n + j];
                    }
                    else
                    {
                        minor[(i - 1) * (n - 1) + j] = source[i * n + j];
                    }
                }
                else
                {
                    if (i < row)
                    {
                        minor[i * (n - 1) + j - 1] = source[i * n + j];
                    }
                    else
                    {
                        minor[(i - 1) * (n - 1) + j - 1] = source[i * n + j];
                    }
                }
            }
        }
    }
}

int determinant(int* a, uint n)
{
    if(n == 1)
    {
        return a[0];
    }
    else
    {
        int sum = 0, sign = -1;

        for(uint i = 0; i < n; ++i)
        {
            int minor[(n-1) * (n-1)];
            initializeMinor(a, minor, n, 0, i);

            sign = (i % 2) ? -1 : 1;
            sum += sign * a[0 * n + i] * determinant(minor, n-1);
        }

        return sum;
    }
}

bool inverseMatrix(int* a, int* inverse, uint n)
{
    int det = determinant(a, N);
    printf("Determinant equals %d\n", det);
    if(det == 0)
    {
        printf("Determinant equals 0. Unable to inverse a matrix\n");
        return false;
    }
    else
    {
	return true;
    }
}

