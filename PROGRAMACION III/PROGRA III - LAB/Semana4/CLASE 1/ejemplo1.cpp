#include <iostream>
#include <vector>
#include <algorithm>


/// Invariante de Bucle

using namespace std;

// Este algoritmo sirve para ordenar numeros de menor a mayor

template<class T>
void insertion_sort(std::vector<T>& v){
    for(std::size_t j = 1; j < v.size(); j++){      // en este bucle, vamos a comenzar a partir del segundo
        int key = v[j];                             // Elemento actual a ser insetado
        int i = j-1;

        while(i >= 0 && v[i] > key){
            v[i+1] = v[i];                          // Intercambio
            i--;
        }
        v[i+1] = key;                               // Se inserta el valor de kaey en la posicion i+1
    }
}

/// El invariante de bucle es una condicion que se cumple en cada iteracion del bucle
template<class C>
void print_container(C container){
    for (const auto e: container)
        cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v(10);

    // Generando un vector con 10 elementos aleatorios de 0 a 99
    generate(v.begin(), v.end(), [](){return rand()%100;});
    print_container(v);

    insertion_sort(v);
    print_container(v);

    return 0;
}