#include <iostream>

using namespace std;

/// ESPECIALIZACION DE CLASES PLANTILLA
// LA ESPECIALIZACION SE PUEDE TAMBIEN USAR EN CLASES


// esta seria la plantilla original
template<class T>
class Foo{
public:
    Foo(){
        cout << "Plantilla Original" << endl;
    }
};

// plantilla especializada, cuando la clase tiene un valor en especifico en este caso cuando se trate de "int"
template<>
class Foo<int>{
public:
    Foo(){
        cout << "Plantilla Especializada" << endl;
    }
};

int main(){
    Foo<float> obj1;    // PLANTILLA ORIGINAL
    Foo<char> obj2;     // PLANTILLA ORIGINAL
    Foo<int> obj3;      // PLANTILLA ESPECIALIZADA

    return 0;
}

/// EN GENERAL
/*
 En general,  si escribimos una clase template el compilador realiza una ""copia de la clase"" cada vez que el ""tipo de dato es distinto"".
 En caso exista ""una especialización"", el compilador primero verifica si existe un match con el tipo de dato y luego con la plantilla principal
 Osea primero el compilador va recorrer la especializacion(es), para verificar si coincide, y si no es asi, se pasa a la plantilla estandar original
 */