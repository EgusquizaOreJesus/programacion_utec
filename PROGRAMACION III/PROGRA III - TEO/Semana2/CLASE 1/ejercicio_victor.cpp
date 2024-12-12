#include "victor.h"

int main(){
    victor v1(10);
    victor v2(10);

    cout << v1;
    cout << v2;

    // con el comando "SWAP" y con el operador de asignacion MOVE, hago esto:
    // con esto muevo los datos de v1 a v2 y los datos de v2 a v1
    swap(v1,v2);       // si v1 data = ptr1, size = 10 && v2 data = ptr2, size = 20
        // al final lo que hace es: v1 data = ptr2, size = 20 && v2 data = ptr1, size = 10 --> LO QUE HACE ES INTERCAMBIAR
    cout << v1;
    cout << v2;

    // En cambio con el comando "MOVE" lo que pasa, es que muevo todo el contenido de v2 a v1, y v2 queda deshabilitado
    v1 = std::move(v2);     //v2 se deshabilita (data_ = nullptr, size = 0)
    cout << v1;
    cout << v2;         //NO IMPRIME NADA, PORQUE YA NO EXISTE

    return 0;
}