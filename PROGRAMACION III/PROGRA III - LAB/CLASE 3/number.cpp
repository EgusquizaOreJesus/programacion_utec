//
// Created by Jesus on 21/01/2023.
//

#include "number.h"

Serie::Serie(int size) {
    random_device rd;
    uniform_int_distribution<int> dis1(0,9);
    uniform_int_distribution<int> dis2(1,9);
    digitos += to_string(dis2(rd));
    for (int i = 0; i < size-1; ++i) {
        digitos += to_string(dis1(rd));
    }
}

ostream &operator<<(ostream &os, const Serie &arr){
    os << arr.digitos << endl;
    return os;
}

// Algoritmo de Luhm
void Serie::Luhm_Algorithm() {
    int checksum = 0;
    for (int pos=1; pos <= digitos.length(); pos++){
        if (pos % 2 != 0)
            checksum += digitos[pos-1] - '0';
        else
            checksum += duplicateDigit(digitos[pos-1] - '0');
    }
    cout << "El checksum es: " << checksum << ".\n";
    if (checksum % 10 == 0)
        cout << "La serie es valida.\n";
    else
        cout << "La serie no es valida\n";
}

int Serie::duplicateDigit(int digito) {
    int digitoDuplicado = digito * 2;
    int sum;

    if (digitoDuplicado >= 10)
        sum = 1 + digitoDuplicado % 10;
    else
        sum = digitoDuplicado;
    return sum;
}
