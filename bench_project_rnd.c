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

#define DATA_SIZE (1024*1024*64*3)
static int MEM_CHUNK[DATA_SIZE];

int main(int argc, char *argv[]){

    int SIZE, N;

    N = (int)atof(argv[1]);
    SIZE = N * N;
    int *a, *b, *c;
    a =  MEM_CHUNK;
    b =  a + N * N;
    c =  b + N * N;
    
    initMatriz_int_rnd(a,b,c,N);
    punto_prueba_inicial();
    //impresionMatriz_int(a,N);
    //impresionMatriz_int(b,N);
    multiplicacionMatricial_int(a,b,c,N);
    //impresionMatriz_int(c,N);
    punto_prueba_final();

    return 0;
}
