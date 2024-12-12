#include <iostream>
#include "algorithm"


using namespace std;

/// FUNCTORS
// CLASES QUE SOBRECARGAN EL OPERADOR "()"
class printString{
private:
    char _end;
public:
    explicit printString(char c = ' '): _end(c) {}

    /// coloco const para que funcione con objetos constantes, SIEMPRE NO OLVIDAR
    // Sobrecarga al operator ()
    void operator() (const string& s) const{
        cout << s << _end;
    }
};
int main(){
    printString line('\n'); // Imprimir en una linea,luego hacer un salto de linea.
    line("Hola");       // de tal manera que los objetos se puedan trabajar como funciones


/// objetos constantes
//  const printString hola('2');
//  hola("hola");

    printString excl('!');  //Imprimir con el simbolo ! al final
    excl("Ingrese un entero valido");

    cout << endl;
    /// GENERALMENTE UN FUNCTOR ES USADO COMO ARGUMENTO PARA OTRO ALGORITMO
    // "for_each" imprimira cada elemento del array con un salto de linea.
    // for_each se usa con la libreria: algorithm

    string v[4] = {"Hola","Mundo","en","C++"};

    for_each(v, v+4, printString('\n'));


    return 0;
}