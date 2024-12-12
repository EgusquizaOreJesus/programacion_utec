#include <iostream>
#include "vector"

using namespace std;
/// PATRONES DE DISEÑO I

/// COMO PUEDO ACCEDER A ESTA FUNCION DE AQUI
// La interface para acceder a dicha funcion es sumar_Valores(vector<int>& v)
// Cuando yo la llamo es ahi cuando yo puedo acceder a esa funcion
int sumar_Valores(vector<int>& v){
    int total = 0;
    for(auto i: v){
        total += i;
    }
    return total;
}

/// PERO QUE PASA SI CAMBIO
//int sumar_Valores(vector<int>& v,int mayor)
// Si hago eso no se podra acceder a dicha funcion, PORQUE SE CAMBIO LA INTERFACE
/// Esto esta rompiendo dos principios:
/// Liskov subsititution principle --> La interface no debe cambiar, solo debe cambiar la implementacion
/// Open-Close principle --> Abierto a la extension, cerrado al cambio

/// COMO HAGO YO PARA SOLUCIONAR DICHO PROBLEMA:
/// No cambio la interface, pero realizo el OPEN-CLOSE, como lo hago: haciendo una sobrecarga
/// CON ESTO YA NO ROMPOR EL PRINCIPIO
int sumar_Valores(vector<int>& v,int max){
    int total = 0;
    for(auto i: v){
        total += i;
    }
    return total;
}

/// EN el caso de clases la interface son toda la zona publica "public:", porque es lo unico que puedo utilizar fuera

/// PATRONES DE CREACION: Son aquellos que proponen diferentes tipos de soluciones para resolver el problema de creacion de un objeto
/// Algunos de ellos son:
// Singleton
// AbstractFactory
// Builder
// Factory


int main() {
    vector<int> v = {1,20,3,40,19};
    auto total = sumar_Valores(v);  // La interface es el unico elemento que me permite interactuar con este codigo es el nombre de la funcion
    // La unica forma de obtener algun valor o utilizar esa funcion es atraves de su interaz


    return 0;
}

