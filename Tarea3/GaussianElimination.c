/* Tarea 3. Metodos Numericos.
    Sistema de ecuaciones 1.

                    José Luis de León Carmona.

Este codigo incluye una subrutina como solucion al ejercicio 3.

Ejercicio 3. Genera un programa en C que resuelva un sistema de ecuaciones de la forma Ax = b, por el m´etodo de
eliminaci´on gaussiana. Para ello debes utilizar el algoritmo de construcci´on de la matr´ız triangular superior
del proceso de eliminaci´on con A = [ai,j ] y b = [bi] para i, j = 1, ..., n
Una vez que se tenga el sistema equivalente de la forma U x = b, utiliza el c´odigo que creaste en el ejercicio 2
para encontrar la soluci´on del sistema de ecuaciones, observa que este paso corresponde a los pasos 8-10 del
algoritmo presentado en clase.

Con esta subrutina resolvemos el insiso a) del 5.

********************************/

#include <stdio.h>


void printArr(int ren, int col, double m[][col]); //Subrutina para imprimir la matriz

void printVec(int dim, double vec[]);

double gaussElimination(int ren, int col, double a[ren][col]);

void Backwardsubstitution(int dim, double U[][dim],double b[dim], double x[dim]);

int main() {
    int dim = 5;


    /* Inciso a)
    double A[][5] = {
        {9, 7, 2, 3, 2},
        {1, 10, 9, 10, 9},
        {3, 8, 9, 1, 8},
        {3, 5, 2, 1, 4},
        {8, 8, 1, 8, 8}

    }; */

    double A[][5] = {
        {2, 20, 18, 20, 18},
        {6, 16, 18, 20, 18},
        {18, 14, 4, 6, 4},
        {16, 16, 2, 16, 16},
        {6, 10, 4, 2, 8}

    };

    printf("Matriz aumentada A: \n");
    printArr(dim, dim, A);
    printf("\n");
    printf("Construcción de la matriz triangular superior por Eliminacion Gaussiana: \n");

    gaussElimination(dim, dim, A);

    printArr(dim, dim, A);
    printf("\n");

    /* inciso a) double b[5] = {51, 133, 90, 43, 99}; */

    double b[5] = {532, 360, 204, 396, 172};

    printf("Vector b: \n");
    printVec(dim, b);
    printf("\n");

    double x[dim]; //Vector que guarda la solucion

    Backwardsubstitution(dim, A,b, x);

    printf("Solucion: \n");
    printVec(dim, x);


    return 0;
}

double gaussElimination(int ren, int col, double a[ren][col]){
    int i,j,k;
    for(i=0;i<ren-1;i++){
        for(k=i+1;k<ren;k++){
            double  aux=a[k][i]/a[i][i];
            for(j=0;j<col;j++){
                a[k][j]=a[k][j]-aux*a[i][j];
            }
        }
    }

}

void Backwardsubstitution(int dim, double U[][dim],double b[dim], double x[dim]) {
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

