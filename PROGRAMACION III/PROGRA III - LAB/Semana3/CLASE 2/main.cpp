#include <iostream>
#include "list"
#include "array"


using namespace std;

/// CONTENEDORES SECUENCIALES

/**
@vector:
 - Rapido acceso a cualquier elemento
@vector:
- Insertar/ Eliminar un elemento
@list:
 - Acceso secuencial bidireccional
 - Rapido al insertar / eliminar cualquier elemento
@forward_list:
 - Acceso secuencial en una sola direccion
 - Rapido al insertar / eliminar cualquier elemento
@array:
 - Rapido acceso a cualquier elemento
 - No se puede añadir / eliminar elementos
@string:
 - Rapido acceso a cualquier elemento
 - Rapido al insertar / eliminar elementos al final
 */


/// ITERADORES
// Un iterador es un objeto que nos permite navegar a traves de los elementos de un contenedor
void ejemplo1(){
    string s = "laptop";
    if (s.begin() != s.end()){
        // s.begin() : un iterador al principio del contenedor
        // s.end()   : un iterador "a uno después" del final del contenedor
        auto it = s.begin();    // it:  apuntara al primer elemento del contenedor(la letra l)
        // podemos reemplazar esta linea por: string::iterator it = s.begin()
        *it = char(toupper(*it)); //aqui capitalizamos la palabra laptop para que sea: Laptop
    }
    cout << s << endl;
}

/// LIST
// Para una lista como tiene acceso bidireccional, acceder a los elementos es complejo,
// Y para iterar entre ellos se usa esta forma:
void ejemplo2(){
    list<int> l = {1,2,4,5};

    // PODEMOS IMPRIMIR TODOS LOS ELEMENTOS DE UNA LISTA DE ESTA MANERA:
    list<int>::iterator i;
    for (i=l.begin(); i!=l.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;
}

///OPERACIONES PERMITIDAS EN ALGUNOS CONTENEDORES:
// *       *it         : Referencia al elemento apuntado por it
// *
// *      it->mem     : El miembro mem del elemento que apunta a it
// *
// *      ++it        : Ahora it apuntara a siguiente elemento
// *
// *      --it        : Ahora it apuntara a elemento previo
// *
// *      it1 == it2  : Compara dos iteradores. Dos iteradores seran iguales si apuntan al mismo elemento
// *
// *      it1 != it2    o si ambos apuntan una posicion mas alla del ultimo elemento (en el mismo contenedor).
// */
///OPERACIONES PERMITIDAS EN CONTENEDORES STRING Y VECTOR:
// *   it + n, it - n  : El resultado es un iterador que apunta a "n" elementos adelante o atras del original.
// *
// *  it += n, it -= n : La misma operacion que la anterior, pero con diferente sintaxis.
// *
// *      it1 - it2    : El resultado es un iterador tal que si añadimos el iterador it2 el resultado sera el iterador it1
// *
// *      >,>=,<,<=    : Un iterador sera menor a otro si este apunta a un elemento en el contenedor que este ubicado
// *                     antes del que apunta el otro iterador
// */

/// QUE CONTENEDOR SECUENCIAL USAR

// AUMENTAR Y ENCOGER EL TAMAÑO:
/// Array: tamaño fijo

// ALMACENA SUS ELEMENTOS DE FORMA CONTIGUA:
/// Vector: De facil y rapido acceso - Insertar o remover elementos del medio tiene un costo computacional

// INSERTAR/ELIMINAR ELEMENTOS EN CUALQUIER POSICION:
/// Listas: Optimizado para las operaciones anteriores



/// funciones IMPORTANTES PARA USO DEL FORWARD_LIST:

/// insert.after: sirve para insertar un valor despues de la posicion tal

/// push_front: me sirve para insertar un valor en la primera posicion

/// pop_front: me sirve para eliminar un valor en la primera posicion

/// remove: lo que hace es eliminar todo los elementos que tengan ese valor

/// remove_if: funcion lamba para calular los numeros pares, lo que hara es remover los elementos si son pares
/// OBS: remove_if, siempre va recorrer todo el contenedor, osea valor por valor para corroborar si se cumple o no dicha condicion

/// find: me permite buscar la posicion de la variable que ponga, si es que no se encuentra me retornara la posicion final
/// osea lista.end()


int main() {
    ejemplo1();
    ejemplo2();
    return 0;
}
