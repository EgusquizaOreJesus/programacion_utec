//
// Created by Jesus on 21/01/2023.
//

#include "numComp.h"

numComp::numComp(int r_, int i_) {
    r = r_;
    i = i_;
}

ostream &operator<<(ostream &os, const numComp& n) {
    os << n.r << " + " << n.i << "i" << endl;
    return os;
}

numComp operator*(const int &k,const numComp &n ) {
    numComp complejo;
    complejo.r = k*n.r;
    complejo.i = k*n.i;
    return complejo;
}

numComp numComp::operator*(const numComp &n) const {
    numComp complejo;
    complejo.r = r*n.r - i*n.i;
    complejo.i = r*n.i + n.r*i;
    return complejo;
}

numComp numComp::operator*(const int &k) const {
    numComp complejo;
    complejo.r = k*r;
    complejo.i = k*i;
    return complejo;
}

numComp numComp::operator+(const numComp &n) const  {           //PONGO const al final, para que acepte la suma de dos numeros complejos declarados como constantes
    numComp complejo;
    complejo.r = r + n.r;
    complejo.i = i + n.i;
    return complejo;
}

numComp numComp::operator-(const numComp &n) const {
    numComp complejo;
    complejo.r = r - n.r;
    complejo.i = i - n.i;
    return complejo;
}




numComp::numComp()=default;
