#include <iostream>

using namespace std;

/// ESPECIALIZACION DE FUNCIONES PLANTILLA

// A diferencia de la sobrecarga, debe existir un emparejamiento entre la funcion template y la especializacion



template<class T>
T Max(T a, T b){
    cout << "T Max(T a, T b): ";
    return a > b ? a: b;
}

// Cuando definimos una especializacion de funcion plantilla, nos estamos haciendo cargo del trabajo del compilador
template<>
char Max(char a, char b){
    cout << "Especializacion Max(char a, char b): ";
    return a > b ? a: b;
}
// NOTA: ESPECIALIZAR = INSTANCIAR
// Una especializacion es una instancia de una plantilla, NO ES UNA SOBRECARGA



int main(){
    // Ambas funciones son viables para este caso, sin embargo, la segunda esta más "especializada", y es la que al final se llama
    cout << Max(2, 1) << endl;
    cout << Max('a', 'b') << endl;
    cout << Max(0.7, 1.5) << endl;

    return 0;
}

//template de template
/*
 *
 */