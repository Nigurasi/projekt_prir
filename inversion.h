#ifndef INVERSE_H_
#define INVERSE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#define EPS 0.0001

typedef unsigned int uint;

int determinant(int* a, uint size);
bool inverseMatrix(int* a, float* inverse, uint size);

#endif //INVERSE_H_
