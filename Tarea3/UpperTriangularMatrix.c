/* Tarea 3. Metodos Numericos.
    Sistema de ecuaciones 1.

                    José Luis de León Carmona.

En este codigo se incluye una subrutina para el ejercicio 2.

Ejercicio 5. Genera un programa en C que resuelva el sistema de ecuaciones de la forma U x = b, d´onde U es una matr´ız
triangular superior.


Y con esta subrutina solucionamos el inciso d) del problema 5.

********************************/

#include <stdio.h>

void printArr(int ren, int col, double m[][col]); //Subrutina para imprimir la matriz

void solveUpper(int dim, double U[][dim], double b[dim], double x[dim]); //Subrutina que resuelve matrices diagonales superiores

void printVec(int dim, double vec[]);

int main() {
    int dim = 5;

    double A[][5] = {
        {9.0, 7.0, 2.0, 3.0, 2.0},
        {0.0, 9.22222, 8.77778, 9.66667, 8.77778},
        {0.0, 0.0, 2.93976, -5.93976, 1.93976},
        {0.0, 0.0, 0.0, -5.22951, 1.59016},
        {0.0, 0.0, 0.0, 0.0, 5.69749}

    };

    double b[] = {51.0, 127.3333, -5.2410, -12.9672, 28.4875};

    double x[dim];

    solveUpper(dim, A, b, x);

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

void solveUpper(int dim, double U[][dim], double b[dim], double x[dim]) {
/* Este algoritmo recibe como argumento una matriz triangular superior de dim x dima
    Ademas del vector B con sus parametros respectivos y un vector x donde se almacena la solucion*/
    int i, j;
    double aux;

    for (i = dim - 1; i > -1; i--) {
        aux = b[i];
        for (j = dim - 1; j > i; j--) {
            aux -= U[i][j]*x[j];
        }
        x[i] = aux/U[i][i];
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
