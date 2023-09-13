/* Tarea 3. Metodos Numericos.
    Sistema de ecuaciones 1.

                    José Luis de León Carmona.

En este codigo se incluye una subrutina para el ejercicio 1.

Ejercicio 1. Genera un programa en C que resuelva el sistema de ecuaciones de la forma Lx = b, d´onde L es una matr´ız
triangular inferior.

Y con esta subrutina solucionamos el inciso c) del problema 5.

********************************/

#include <stdio.h>

void printArr(int ren, int col, double m[][col]); //Subrutina para imprimir la matriz

void solveLower(int dim, double L[][dim], double b[dim], double x[dim]); //Subrutina que resuelve matrices diagonales inferiores

void printVec(int dim, double vec[]);

int main() {
    //Matriz del inciso c) del problema 5.

    int dim = 5;
    double A[][5] = {
        {1.0, 0.0, 0.0, 0.0, 0.0},
        {0.11111, 1.0, 0.0, 0.0, 0.0},
        {0.33333, 0.61446, 1.0, 0.0, 0.0},
        {0.33333, 0.28916, -0.40984, 1.0, 0.0},
        {0.88889, 0.19277, -0.84016, 0.29075, 1.0}
    };

    double b[] = {51, 133, 90, 43, 99};

    double x[dim];

    solveLower(dim, A, b, x);

    printf("Tu matriz A: \n");

    printArr(dim, dim, A);
    printf("\n");

    printf("Y tu vector b: \n");

    printVec(dim, b);
    printf("\n");

    printf("Tienen como solucion el vector x: \n");

    printVec(dim, x);


    return 0;
}


void solveLower(int dim, double L[][dim], double b[dim], double x[dim]) {
    int i, j;
    double aux;

    for (i=0; i < dim; i++ ) {
        aux = b[i];
        for (j=0; j<i; j++) {
            aux -= L[i][j]*x[j];
        }
        x[i] = aux/L[i][i];
    }
}


void printArr(int ren, int col, double m[][col]) {
    int i, j;

    for (i = 0; i < ren; i++) {
        for (j = 0; j < col; j++) {
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
}

void printVec(int dim, double vec[]) {
    int i;

    for (i = 0; i < dim; i++) {
        printf("%lf \n", vec[i]);
    }

}
