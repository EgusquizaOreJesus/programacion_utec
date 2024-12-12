//
// Created by Jesus on 21/01/2023.
//

#ifndef CLASE_1_NUMEROS_H
#define CLASE_1_NUMEROS_H
#include "iostream"
template<typename T1, typename T2>
class Numeros {
    T1 _x;
    T2 _y;
public:
    Numeros(T1 x, T2 y){
        _x = x;
        _y = y;
    }
    T1 sumar(){return _x+_y;}
    T1 resta(){return _x-_y;}
    T1 producto(){return _x*_y;}
    float division(){return _x/_y;}

};


#endif //CLASE_1_NUMEROS_H
