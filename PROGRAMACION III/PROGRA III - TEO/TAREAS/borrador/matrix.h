#ifndef TAREA1_MATRIX_H
#define TAREA1_MATRIX_H

#pragma once
#include <iostream>


using std::ostream;

using SizeType = size_t;    // typedef size_t, el "size_t" es equivalente a un "unsigned int"
using Type = int;           // En ves de llamar a una variable int lo llamo por "Type" ES UN ALIAS

class Matrix {
    // Attributes
protected:
    Type** data_ = nullptr;          //definiendo e inicializando el atributo(inicializacion in-class "dentro de la clase")
    SizeType rows_ = SizeType {};   // inicializando los atributos con valores por defecto
    SizeType cols_ = SizeType {};   // esta forma es lo mismo que ponerle 0, que se inicializa en nulo
public:
    // Constructs and Destroy
    explicit Matrix(SizeType rows, SizeType cols);      // se coloco el "explicit" para decir que este constructor se usara de forma explicita
    Matrix(const Matrix& other);                    // CONSTRUCTOR COPIA
    //Matrix(Matrix&& other) noexcept;                // CONSTRUCTOR MOVE
    Matrix& operator=(const Matrix& other);         // OPERADOR DE ASIGNACION COPIA
    Matrix& operator=(Matrix&& other) noexcept;     // OPERADOR DE ASIGNACION MOVE
    ~Matrix(); // destructor
    [[nodiscard]] SizeType rows() const;
    [[nodiscard]] SizeType cols() const;
    void liberar();
    // Operators
    // aqui estoy sobrecargando el simbolo de "()"
    Type& operator() (int i_row, int i_col);                    // se comporta como un set
    Type operator() (int i_row, int i_col) const;               // se comporta como un get
    friend ostream& operator<<(ostream& os, const Matrix& m);
    bool operator==(const Matrix& c1);
    bool operator!=(const Matrix& c1);
    Matrix operator*(const Matrix& c1);
    Matrix operator*(const Type& c1);
    Matrix operator*=(const Type& c1);
    friend Matrix operator*(const Type& c1,const Matrix& m);
    Matrix operator+(const Matrix& c1);
};
Matrix operator*(const Type& c1,const Matrix& m);



ostream& operator<<(ostream& os, const Matrix& m);
#endif //TAREA1_MATRIX_H
