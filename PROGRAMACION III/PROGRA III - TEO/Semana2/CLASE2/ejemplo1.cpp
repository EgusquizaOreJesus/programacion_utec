#include "iostream"

using namespace std;


// diferencia entre poner (pack op ...) and (... op pack)
// en el primer caso comienza tomando el penultimo valor con el ultimo, y lo va operando
// y asi sucesivamente recursivamente hasta acabar desempaquetando todas las variables
template<typename ... Ts>
auto resta1(Ts ... ts){
    return (ts - ...);      //Fold expression
}
// en el segundo caso comienza tomando el primer valor con el segundo, y lo va operando
// y asi sucesivamente recursivamente hasta acabar desempaquetando todas las variables
template<typename ... Ts>
auto resta2(Ts ... ts){
    return (... - ts);      //Fold expression
}

template<typename ... Ts>
void print(Ts ... ts) {
    (cout << ... << ts);
}
int main(){
    cout << resta1(1,2,3.4,2) << endl;
    // lo que hace esta funcion template complejas es:
    /*
     1° resta el penultimo valor con el ultimo
     3.4 - 2 --> 1.4
     dicho valor se empaqueta en ts --> (1,2,1.4)
     2° y hace el mismo proceso recursivamente
     2 - 1.4 --> 0.6
     dicho valor se empaqueta en ts --> (1,0.4)
     y hace el proceso recursivamente
     1-0.6 --> 0.4
     resultado final = 0.6.
     */
    cout << resta2(1,2,3.4,2) << endl;
    // lo que hace esta funcion template complejas es:
    /*
     1° resta el primer valor con el segundo
     1 - 2 --> -1
     dicho valor se empaqueta en ts --> (-1,3.4,2)
     2° y hace el mismo proceso recursivamente
     -1 - 3.4 --> -4.4
     dicho valor se empaqueta en ts --> (-4.4,2)
     y hace el proceso recursivamente
     -4.4-2 --> -6.4
     resultado final = -6.4.
     */
    print("El resultado es:", 10 + 20);
    return 0;
}

