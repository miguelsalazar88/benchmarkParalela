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

struct timespec inicioCuenta, finCuenta;

void punto_prueba_inicial(){
    clock_gettime(CLOCK_MONOTONIC, &inicioCuenta);  
}

void punto_prueba_final(){
    double total_time;
    clock_gettime(CLOCK_MONOTONIC, &finCuenta);
    total_time = (finCuenta.tv_sec - inicioCuenta.tv_sec) * 1e9;
    total_time = (total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec) * 1e-9;
    printf("%f", total_time);

}

void initMatriz_int(int *a, int *b, int *c, int N){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            a[i + j * N] = 3 * (i+j);
            b[i + j * N] = 2 * (j-i);
            c[i + j * N] = 0;
        }   
    }
}
    
    
void multiplicacionMatricial_int(int *matrizA, int *matrizB, int *matrizC, int N){
        
    for (int i = 0; i < N; i++) {
        for (int j=0; j<N; j++){
            int suma = 0;
            int *pA, *pB;
            pA = matrizA + (j*N);
            pB = matrizB + i;
            for(int k = 0; k<N; k++, pA++, pB+=N){
                suma += (*pA * *pB);

            }
            matrizC[j+i*N] = suma * (-1);
        }
    }     
}
    
void impresionMatriz_int(int *matriz, int N){
    for (int i = 0; i < N; i++){
        printf("\n");
        for (int j = 0; j < N; j++){
            printf("%d \t", matriz[i + j * N]);
        }
        
    }
    printf("\n");
}
