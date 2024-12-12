#include <iostream>

using namespace std;

// Especializacion de la sobrecarga
template<class T>
string Tipo1(T a){
    return "No es puntero.";
}

// sobrecargando la funcion template para caso especifico en que sea tipo de dato puntero
template<class T>
string Tipo1(T* a){
    cout << "SOBRECARGA A LA FUNCION PARA DATO PUNTERO" << endl;
    return "Es puntero.";
}

// especializando la funcion template, para que si es un tipo de dato puntero en especifico me arroje este msj
template<>
string Tipo1(int* a){
    cout << "ESPECIALIZACION A LA FUNCION PARA PUNTERO ENTERO" << endl;
    return "Es puntero 'int'.";
}

int main(){
    float x1 = 0;
    char* y1 = nullptr;
    int* z1 = nullptr;

    // validando los tipos de datos con las plantillas
    cout << Tipo1(x1) << endl;
    cout << Tipo1(y1) << endl;
    cout << Tipo1(z1) << endl;
    return 0;
}