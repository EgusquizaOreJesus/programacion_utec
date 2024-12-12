//
// Created by Jesus on 21/01/2023.
//

#ifndef CLASE_1_VICTOR_H
#define CLASE_1_VICTOR_H
#include "iostream"
#include "algorithm"
#include "random"

using namespace std;
class victor {
    int* data = nullptr;
    size_t size_ = int{};
public:
    // LOS DOS PRIMEROS CONSTRUCTORES SON COMPLEMENTARIOS, OPCIONALES
    // Si no necesito parametros, NO IMPLEMENTO EL CONSTRUCTOR POR PARAMETROS
    // SI NO NECESITO un constrcutor por default, No lo pongo
    victor() = default;             // DEFAULT CONSTRUCTOR
    explicit victor(size_t size);            // CONSTRUCTOR POR PARAMETROS

    // LOS CONSTRUCTORES DE ACA, Y SUS RESPECITVOS OPERADORES DE ASIGNACION SOLAMENTE
    // IMPORTANTE SE IMPLEMENTAN CUANDO USO "MEMORIA DINAMICA"
    // Si uso contenedores, NO SON NECESARIOS
    victor(const victor& other);    // CONSTRUCTOR COPIA
    victor(victor&& other) noexcept ;         // CONSTRUCTOR MOVE

    ~victor();
    // SOBRECARGA A LOS OPERADORES DE ASIGNACION
    victor& operator=(const victor& other);      // operador de copia, que actua como un constructor COPIA
    victor& operator=(victor&& other) noexcept ;            // operador de MOVE, que actua como un constructor MOVE

    friend ostream& operator<<(ostream& os, const victor& v1);

};


#endif //CLASE_1_VICTOR_H
