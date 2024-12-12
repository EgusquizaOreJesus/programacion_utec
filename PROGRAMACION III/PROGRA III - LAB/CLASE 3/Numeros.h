//
// Created by Jesus on 20/01/2023.
//

#ifndef CLASE_3_NUMEROS_H
#define CLASE_3_NUMEROS_H

#include <iostream>
#include "random"


using std::ostream;
using SizeType = size_t;

class Numeros {
    int* arr = nullptr;
    SizeType tam_ = SizeType {};
public:
    explicit Numeros(SizeType tam);

    [[nodiscard]] SizeType tam() const;       //get para obetener el tamaño

    int& operator() (int i);               // Equivalente al set, aqui se retorna una referencia de "a", y para el caso del set si es necesario poner "&"
    int operator() (int i) const;        // Equivalente al get
    friend ostream &operator<<(ostream &os, const Numeros &arr);        //sobrecarga al operador de << para imprimir el array

    //method find_mode
    SizeType mode();
    void insertion_sort_array();
    int max_element();



};


#endif //CLASE_3_NUMEROS_H
