#ifndef INVERSE_H_
#define INVERSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 2

typedef unsigned int uint;

void initializeMinor(int* source, int* minor, uint size, uint row, uint column);
int determinant(int* a, uint n);
void inverseMatrix(int* a);

#endif //INVERSE_H_
