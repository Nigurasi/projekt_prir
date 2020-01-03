#include "inversion.h"

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
                        minor[i * size + j] = source[i * size + j];
                    }
                    else
                    {
                        minor[(i - 1) * size + j] = source[i * size + j];
                    }
                }
                else
                {
                    if (i < row)
                    {
                        minor[i * size + j - 1] = source[i * size + j];
                    }
                    else
                    {
                        minor[(i - 1) * size + j - 1] = source[i * size + j];
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
        int sum = 0, sign = 1;

        for(uint i = 0; i < n; ++i)
        {
            int minor[(n-1) * (n-1)];
            initializeMinor(a, minor, n-1, 0, i);

            sign = (i % 2) ? -1 : 1;
            sum += sign * a[0 * n + i] * determinant(minor, n-1);
        }

        return sum;
    }
}

void inverseMatrix(int* a)
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

