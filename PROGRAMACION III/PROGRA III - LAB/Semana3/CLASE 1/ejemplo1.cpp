#include <iostream>

using namespace std;

/// CALLBACKS
// Funciones de callback



int suma(int x1, int x2){ return x1 + x2; }
int resta(int x1, int x2){ return x1 - x2; }

// Es posible crear una funcion que admite como entrada otra funcion o funciones
void calculadora(int(*f)(int, int), int x1, int x2){     // Puedo utilizar un puntero a una funcion como parametro "int(*f)(int, int)"
    int resultado = f(x1,x2);
    cout << resultado << endl;
}

/// void calculadora(int(*f)(int, int), int x1, int x2)
// int(*f)(int, int):
// int:         Tipo de dato que retorna, puede ser "void"
// *f:          Se pasa un puntero a la funcion, eficiencia
// (int,int):   Tipos de datos que requiere la funcion "f"

// int x1, int x2:  Parametros adicionales

int main(){
    calculadora(&suma,3,2);     // Las funciones "suma" y "resta" deben ser del mismo tipo de "f"
    // por eso usamos la referencia "&", para sacar su direccion de dicha funcion.
    calculadora(&resta,3,2);

    /// Podemos tambien crear una varialbe de tipo puntero que contenga a la funcion "suma"
    // Para hacer eso lo asignamos de esta manera:
    int (*var_f)(int,int);

    var_f = &suma;
    calculadora(var_f, 3, 2);

    // del mismo modo para la resta:
    var_f = &resta;
    calculadora(var_f, 3, 2);

    return 0;
}
