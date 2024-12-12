//
// Created by Jesus on 21/01/2023.
//

#ifndef CLASE4_MATRIX_H
#define CLASE4_MATRIX_H

#include "iostream"
#include "random"
#include "iomanip"

using namespace std;


class matrix2 {
    int** data_ = nullptr;
    int rows_ = int {};
    int cols_ = int {};
    void liberar();
public:
    explicit matrix2(int row, int cols);
    int operator()(int row, int cols) const;            //sobrecarga al operador () para obtener un elemento especifico de la matriz
    matrix2(const matrix2& other);                    // CONSTRUCTOR COPIA

    ~matrix2();

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;

    friend ostream& operator<<(ostream& os, const matrix2& m);
    matrix2& operator=(const matrix2& other);         // OPERADOR DE ASIGNACION COPIA


    matrix2 operator+(const matrix2& m) const;


};


#endif //CLASE4_MATRIX_H
