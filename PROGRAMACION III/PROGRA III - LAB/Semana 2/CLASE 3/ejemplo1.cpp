#include <iostream>


/// SOBRECARGA DE FUNCIONES PLANTILLA
// Uno puede declarar varias funciones-plantilla o funciones ordinarias con el mismo nombre.

// En estos casos la resolución de sobrecarga se realiza de acuerdo a la deducción de argumento de plantilla.

// De esta manera se encuentra la especialización que se ajuste mejor a los argumentos.

using namespace std;

template<class T>
T Max(T a, T b){
    cout << "T Max(T a, T b): ";
    return a > b ? a: b;
}

// SOBRECARGA DE UNA FUNCION PLANTILLA
// Dicha sobrecarga si se da, me retornara un entero cualquiera
int Max(char a, int b){
    cout << "SOBRECARGA A DICHA FUNCION" << endl;
    cout << "T2 Max(T1 a, T2 b): ";
    return a > b ? a: b;
}

int main(){
    cout << Max(2, 1) << endl;      //comparar dos enteros, usa la funcion plantilla
    cout << Max('a', 'b') << endl;  // Comparar dos caracteres, usa la funcion plantilla
    cout << Max(0.7, 1.5) << endl;  // Comparar dos decimales, usa la funcion plantilla
    cout << Max('a', 1) << endl;    // Comparar un caracter y un entero. Para este caso el template no podra deducirlo
    // En este caso de ambiguedad, ES NECESARIO IMPLEMENTAR SOBRECARGAS ESPECIFICAS PARA RESOLVER DICHA LLAMADA
    return 0;
}

