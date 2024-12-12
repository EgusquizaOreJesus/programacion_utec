#include <iostream>
#include "numeric"
#include "algorithm"
#include "vector"


/// RECORDANDO UN POCO DE LA CLASE PASADA
/// Los algoritmos son funciones de tipo template, que permiten manipular los contenedores
// DICHOS ALGORITMOS PUEDEN ESTAR EN LA LIBRERIA "algorithm" o "numeric"
/// Mayormente los algoritmos estan conformados por tres elementos:
/// algorithm( iteradores, valores, funciones o cualquier estructura que se comporte como una funcion)



/// Pueden utilizarse los mismos tipos de algoritmos para cualquier tipo de contenedor
/// Obveamente tiene sus limitantes

/// Acordando un poco:

/// Vector
// Eficiente para insertar elementos atras

/// Deque
// Eficiente para insertar elementos atras y adelante

/// Lista
// Con la misma eficiencia logra insertar valores en cualquier posicion

using namespace std;


/// Ejemplo de usando un algoritmo copy para copiar elementos de un contenedor a otro
void ejemplo1(){
    vector v = {10,20,30,40};

    vector<int> v2(v.size());       //creo un vector v2 de tamaño v
    // Copiando v  en v2
    /// Lo que hace es recorrer el vector v, elemento por elemento (v.begin(),v.end())
    /// Y lo copia en v2.
    copy(v.begin(),v.end(), begin(v2));
    // Esto es equivalente a usar un for con push_back

    //Imprimo los valores que se encuentran en el vector:
    for_each(v.begin(),v.end(),[](int x){cout << x << " ";});


}

bool EsCompuesto(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i==0){
            return true;
        }
    }
    return false;
}

bool EsPrimo(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i==0){
            return false;
        }
    }
    return true;
}


/// Si quiero copiar elementos de un vector a otro que no tiene tamaño usa esta funcion:
/// back_inserter. Con dicha funcion es parecida al push_back, y sirve para copiar elementos de un vector a otro que no tiene tamaño
void ejemplo2(){
    vector v = {10,20,30,40};

    vector<int> v2;       //creo un vector v2 de tamaño v
    // Copiando v  en v2
    /// Lo que hace es recorrer el vector v, elemento por elemento (v.begin(),v.end())
    /// Y lo copia en v2.
    copy(v.begin(),v.end(), back_inserter(v2));

    //Imprimo los valores que se encuentran en el vector:
    for_each(v.begin(),v.end(),[](int x){cout << x << " ";});
}

/// Si no quisiera copiar todos los elementos sino algunos que cumplan cierto criterio
/// Entonces en estos casos el vector no se sabra cual es su tamaño, por lo que se necesitara otra funcion a implementar
/// "copy_if" : Esto copia solamente los elementos que cumplan cierta condicion
/// Estructura del copy_if:
/// (iteradores recorriendo contenedor a copiar, contenedor donde se copiara, condicion para copiar)
void ejemplo_copy_if(){
    vector v = {10,20,30,40,7,3};

    vector<int> v2;       //creo un vector v2 de tamaño v
    vector<int> v3;

    copy_if(v.begin(),v.end(), back_inserter(v2),[](int x){
        if (x%3==0){
         return true;
        };
        return false;
    });

    /// Poniendo una condicion que copie solo los numeros primos:
    /// Fijate que se usara dos funciones, una para insertar y la otra para filtrara y solamente insertar cierto valor
    copy_if(v.begin(),v.end(), back_inserter(v3), (EsPrimo));

    /// Imprimiendo los valores de cada vector
    for_each(v2.begin(),v2.end(),[](int x){cout << x << " ";});
    cout << endl;
    for_each(v3.begin(),v3.end(),[](int x){cout << x << " ";});
}


/// Ahora si quisieramos buscar un elemento en un contenedor, hay tambien algoritmos de busqueda
void ejemplo_busqueda(){
    vector v = {10,20,30,40,7,3};

    /// Hacemos uso de la funcion "find", que lo que hace es retorname el iterador donde se encuentra el valor buscado
    /// Iterando sobre todo el contenedor (v.begin(),v.end())

    /// Le digo que busque el valor de 6,
    /// Aqui se puede observar que este es un tipo de algoritmo que en vez de usar funciones usa valores

    auto it = find(v.begin(),v.end(),7);
    cout << *it;

}

/// Entonces acuerdate usualmente los algoritmos estan conformados por tres elementos:
/// (iteradores (que definene rangos), valores (que definen si se quiere buscar o insertar un valor), funciones  )
/// Y los algoritmos hay ciertos tipos que no son modificables, y otros que si modifican el contenedor

/// INVESTIGAR ordenamiento estable y no estable



int main() {

    ejemplo_copy_if();
    return 0;
}
