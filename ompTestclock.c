/*                                                 */
/*  Program ompTestclock.c                         */
/*  Odczytywanie czestotliwosci zegara procesorow  */
/*                                                 */
#include <stdio.h>
#include <omp.h>

void main(){
   double timerd, czestotl;
   #pragma omp parallel private(timerd, czestotl)
   {
       timerd=omp_get_wtick();
       czestotl=1./(1.e9*timerd);
       printf("wtick=%20.20lf\n", timerd);
       printf("czestotliwosc zegara=%lf GHz\n", czestotl);
   }
}
