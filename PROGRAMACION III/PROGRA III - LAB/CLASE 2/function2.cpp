//
// Created by Jesus on 14/01/2023.
//
#include "function2.h"


int** crear_matriz(int n, int m){
    int** mat = new int*[n];
    for(int i=0; i<n; i++){
        mat[i] = new int[m];
        for(int j=0; j<m; j++){
            mat[i][j] = 10 + rand() % 90;
        }
    }
    return mat;
}

void print_matriz(int **mat, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

float promedio_matriz(int **mat, int n, int m) {
    float s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            s += mat[i][j];
        }
    }
    return (s/(n*m));
}
void print_suma(int** mat1, int** mat2, int n, int m){
    for(int i=0; i<n; i++){
        cout << "| ";
        for(int j=0; j<m; j++){
            cout.width(3); // me permite que la matriz este recta
            cout << setw(5)<<mat1[i][j] + mat2[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

// LIBERAR MEMORIA DE UNA MATRIZ DINAMICA
void liberar(int** M, int n){
    // CUANDO HAGO EL BORRADO DE UNA MATRIZ DINAMICA, TIENES QUE BORRAR TANTO EL
    // ARRAY DE PUNTEROS QUE CREE OSEA EL PUNTERO DOBLE
    // Y LOS VALORES DE CADA FILA, YA QUE CADA FILA ES UN PUNTERO QUE APUNTA A UN ARRAY
    for (int i = 0; i < n; ++i) {
        delete[] M[i]; //elimino filas --> porque cada fila es un puntero que apunta a un array
    }
    delete[] M; //POR ULTIMO ELIMINO EL ARRAY DE PUNTEROS INICIAL
}