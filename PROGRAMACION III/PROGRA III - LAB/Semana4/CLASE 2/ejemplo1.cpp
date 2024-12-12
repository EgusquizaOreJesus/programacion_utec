#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

/// NOTACION BIG O

/// Tiempo constante O(1)
// Sin importar el tipo de entrada o tamaño, al algoritmo el mismo tiempo realizar el mismo trabajo
// Ejm:
//  POSNEG(n):
//  if n > 0                                O(1)
//    imprimir “n es positivo”              O(1)
//  else                                    O(1)
//    imprimir “n no es positivo”           O(1)

//Si un algoritmo realiza un número fijo de pasos para resolver un problema,
// no importa si es 1, 10, 1000 o 1M, este seguirá siendo de tiempo constante.
// Notacion T(n) = O(1)
// Ejm:
// Si el algoritmo requiere 100 pasos para resolver un problema, entonces T(n)=100m. En otras palabras, T(n) = O(1).

/// TIEMPO LINEAL
/**
 * La gran mayoría de los algoritmos no son de tiempo constante. Habitualmente, el trabajo que realiza un algoritmo depende del tamaño de la entrada.

Trabajo de procesar 1000 elementos > Trabajo de procesar 10 elementos


En el caso que un algoritmo de tiempo lineal se ejecute primero con una entrada de 50 elementos y luego con otra 100 elementos. El algoritmo realizará el doble de trabajo en segundo caso.


 */

/// Un algoritmo de tiempo lineal tienen relación directa con el tamaño de la entrada
// Notación: T(n) = O(n)
// Si el algoritmo requiere 10n pasos para resolver un problema, entonces T(n)=10n. En otras palabras, T(n) = O(n).
// Si T(n)=10n + 5, entonces T(n) = O(n).

/// TIEMPO CUADRATICO
/**
En un algoritmo de tiempo cuadrático el trabajo realizado por el algoritmo también depende del tamaño de la entrada. Estos lucen de la siguiente manera:
@ejem:
@ejem:for i=0 to n-1
@ejem:    for j=0 to n-1
@ejem:       sentencia

 */
//Si para resolver un problema, un algoritmo necesita n2 pasos para revolverlo y otro algoritmo requiere n pasos, ¿Cuál escogería?
//
//Supongamos que se tiene 100 elementos, entonces:
//
//El algoritmo de tiempo lineal realizará 100 pasos  para resolver el problema.
//El algoritmo de tiempo cuadrático necesitará 10000 pasos, lo cual es más costoso.


using namespace std;

template<class C>
void print_container(C& cont){
    for (auto it=cont.begin(); it!=cont.end(); it++)
        cout << *it << " ";
    cout << endl;
}

template<class It>
void print_container(It begin, It end){
    for (auto it=begin; it!=end; it++)
        cout << *it << " ";
    cout << endl;
}

int main(){
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    vector<float> v(10);
    generate(v.begin(), v.end(), [](){return static_cast<float>(rand())/RAND_MAX;});

    inicio = chrono::high_resolution_clock::now();
    //print_container(v);
    print_container(v.begin(), v.end());

    fin    = chrono::high_resolution_clock::now();
    //auto t = chrono::duration_cast<chrono::millioseconds>(fin - inicio).count();
    //cout << t << "ms" << endl;

    std::chrono::duration<double, std::milli> t = fin - inicio;
    cout << "time = " << t.count() << "ms" << endl;

    return 0;
}