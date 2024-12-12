#ifndef TAREA1_MATRIX_H
#define TAREA1_MATRIX_H

#pragma once
#include <iostream>


using std::ostream;

using SizeType = size_t;
using Type = int;

class matrix {
    // Attributes
protected:
    Type** data_ = nullptr;          //definiendo e inicializando el atributo(inicializacion in-class "dentro de la clase")
    SizeType rows_ = SizeType {};   // inicializando los atributos con valores por defecto
    SizeType cols_ = SizeType {};   // esta forma es lo mismo que ponerle 0, que se inicializa en nulo
public:
    // Constructs and Destroy
    //Matrix();
    explicit matrix(SizeType rows, SizeType cols);      // se coloco el "explicit" para decir que este constructor se usara de forma explicita
    matrix(const matrix& other);                    // CONSTRUCTOR COPIA
    matrix(matrix&& other) noexcept;                // CONSTRUCTOR MOVE
    matrix& operator=(const matrix& other);         // OPERADOR DE ASIGNACION COPIA
    matrix& operator=(matrix&& other) noexcept;     // OPERADOR DE ASIGNACION MOVE
    ~matrix(); // destructor
    [[nodiscard]] SizeType rows() const;
    [[nodiscard]] SizeType cols() const;
    void liberar();
    // Operators
    // aqui estoy sobrecargando el simbolo de "()"
    Type& operator() (int i_row, int i_col);                    // se comporta como un set
    Type operator() (int i_row, int i_col) const;               // se comporta como un get
    friend ostream& operator<<(ostream& os, const matrix& m);
    bool operator==(const matrix& c1);
    bool operator!=(const matrix& c1);
    matrix operator*(const matrix& c1);
    matrix operator*(const Type& c1);
    matrix operator*=(const Type& c1);
    friend matrix operator*(const Type& c1,const matrix& m);
    matrix operator+(const matrix& c1);
};
matrix operator*(const Type& c1,const matrix& m);
ostream& operator<<(ostream& os, const matrix& m);
#endif //TAREA1_MATRIX_H
