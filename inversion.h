#ifndef INVERSE_H_
#define INVERSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 3

typedef unsigned int uint;

int determinant(int* a, uint n);
bool inverseMatrix(int* a, int* inverse, uint n);

#endif //INVERSE_H_
