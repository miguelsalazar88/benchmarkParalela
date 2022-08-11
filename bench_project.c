/*******************************************************
 * 9 de agosto de 2022
 * Autor: Miguel Salazar 
 * Construccion Benchmark Multiplicación de Matrices
 *****************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "bench.h"
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>


int main(int argc, char *argv[]){

    int SIZE, N;

    N = (int)atof(argv[1]);
    SIZE = N * N;
    int a[SIZE], b[SIZE], c[SIZE];
    
    initMatriz(a,b,c,N);
    punto_prueba_inicial();
    multiplicacionMatricial(a,b,c,N);
    punto_prueba_final();
}
