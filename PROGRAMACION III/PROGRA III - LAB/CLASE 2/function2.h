#include <bits/stdc++.h>

using namespace std;

#ifndef CLASE_2_FUNCTION2_H
#define CLASE_2_FUNCTION2_H

// crear matriz dinamica con numeros enteros aleatorios del 1 al 99;
int** crear_matriz(int n, int m);

// print matriz dinamica
void print_matriz(int** mat, int n, int m);

float promedio_matriz(int** mat, int n, int m);

void print_suma(int** mat1, int** mat2, int n, int m);

void liberar(int** M, int n);
#endif //CLASE_2_FUNCTION2_H
