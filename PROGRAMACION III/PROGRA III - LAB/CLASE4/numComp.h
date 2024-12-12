//
// Created by Jesus on 21/01/2023.
//

#ifndef CLASE4_NUMCOMP_H
#define CLASE4_NUMCOMP_H

#include "iostream"

using namespace std;

class numComp {
    int r = int{};      //parte real
    int i = int{};      // parte imaginaria
public:
    numComp();
    explicit numComp(int r_,int i_);

    friend ostream& operator<<(ostream& os, const numComp& n);

    numComp operator+(const numComp& n) const;

    numComp operator-(const numComp& n) const;

    numComp operator*(const numComp& n) const;
    numComp operator*(const int& n) const;
    friend numComp operator*( const int& k, const numComp& n);


};


#endif //CLASE4_NUMCOMP_H
