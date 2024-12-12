#include <iostream>

using namespace std;

template<class T>
T Max(T a, T b){
    return a > b ? a: b;
}

// realizo una sobrecarga a dicha funcion template, para el caso cuando sean multibles valores
// en dicha sobrecarga de la funcion plantilla
// lo que haremos es agarrar los dos primeros valores, y el resto los empaqueto
// luego llamo a la misma funcion Max, para de dichos valores me arroje su maximo,
// el numero mas grande se mantiene junto con el resto empaquetado
// y retornamos denuevo la funcion, y asi recursivamente, hasta que acabe de desempaquetar todo los valores

template<class T, class...Ts>
T Max(T a, T b, Ts... args){
    return Max(Max(a,b),args...);
}

// pero esto acepta parametros del mismo tipo de variable si quisiera comparar un float y entero cual es mayor
// tendria que hacer asi:

template<class T>
T Max2(T a, double b){
    return a > b ? a: b;
}

template<class T, class...Ts>
T Max2(T a, double b, Ts... args){
    return Max2(Max2(a,b),args...);
}


int main(){
    cout << Max(3,4) << endl;
    cout << Max(1,2,3,4,5) << endl;
    // Max(1,2,3,4,5) --> agarra a=1, y b=2, y return el mayor con el resto del conjunto y asi recursivamente
    // Max(2,3,4,5)->Max(3,4,5)->Max(4,5)-- > ESTO ES LO QUE HACE INTERNAMENTE
    cout << Max(3,3,2,7,1,0) << endl;
    cout << Max(3,3,2,7,1,0) << endl;

    // COMPARANDO ENTEROS Y DOUBLE
    cout << Max2(3,3,2,7,1,0) << endl;
    cout << Max2(8.2,3,2,7,1,0) << endl;
    cout << Max2(8.2,3.4,2.2,7,9.3,7.3,3,5.4,2) << endl;

    return 0;
}

// print(2,3,4,5,6) # Salida:2 3 4 5 6
// vec.push_back(34,5,6,7)