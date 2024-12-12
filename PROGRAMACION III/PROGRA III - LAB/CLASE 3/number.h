//
// Created by Jesus on 21/01/2023.
//

#ifndef CLASE_3_NUMBER_H
#define CLASE_3_NUMBER_H

#include "iostream"
#include "random"

using namespace std;

class Serie {
    string digitos = {};
    static int duplicateDigit(int digito);
public:
    explicit Serie(int size);

    friend ostream &operator<<(ostream &os, const Serie &arr);        //sobrecarga al operador de << para imprimir la serie

    // method Luhm Algorithm
    void Luhm_Algorithm();

};


#endif //CLASE_3_NUMBER_H
