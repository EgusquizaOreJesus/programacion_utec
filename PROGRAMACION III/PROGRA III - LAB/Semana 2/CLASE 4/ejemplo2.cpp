#include <iostream>

using namespace std;

/// VARIADIC TEMPLATE
// Es una funcion template o clase template que acepta un pack/conjunto de parametros


template<typename ... Ts>   //... Ts --> representa un conjutno de elementos empaquetados
void foo(Ts... args){       // --> args: aqui el conjunto de elemtnos los desempaqueto para poder manipular cada uno
    cout << sizeof...(args) << endl;
    // sizeof --> me permite obtener el numero de parametros
    // esta sintaxis me permite visualizar el numero de parametros
}


/// PARA PODER ITERAR A TRAVES DE LOS ARGUMENTOS
// NO PODEMOS USAR bucles for para iterar a traves de ellos
// se usara:
/// FOLD EXPRESSIONS
/// Expresión de Pliegue del operador +
// return (args+...);
template<typename... Ts>
auto suma(Ts... args){
    return (args+...);
    // LO QUE ESTA HACIENDO ES UNA RECURSIVIDAD ASI:
    // args+... = arg1 + (arg2 + ... ))
}

/// En terminos generales para todo tipo de operador:
//  ""args op ... "" = arg1 op (arg2 op . . . ))
int main(){
    cout << "Utilizando 'sizeof...'" << endl;
    foo(1,2);
    foo(1,2,3,3,4,5);
    foo();

    cout << "Utilizando 'suma'" << endl;
    cout << suma(1) << endl;
    cout << suma(1,2) << endl;
    cout << suma(1,2,3,4,5) << endl;

    return 0;
}