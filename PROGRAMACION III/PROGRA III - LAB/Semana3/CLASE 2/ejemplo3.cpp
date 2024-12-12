#include <iostream>
#include <forward_list>

using namespace std;
/// OPTIMIZADOS PARA ESTAS OPERACIONES
// Listas y forward_list


/// OPERACIONES PERMITIDAS EN FORWARD_LIST
/// FUNCIONES IMPORTANTES
int main(){
    forward_list<int> lista = {1,4,5};

    cout << "Lista Original:" << endl;
    cout << "================" << endl;
    forward_list<int>::iterator i;
    for (i = lista.begin(); i != lista.end(); i++)
        cout << *i << endl;

    /// insert.after: sirve para insertar un valor despues de la posicion tal
    // En este caso insertare un valor despues de la posicion inicial
    lista.insert_after(lista.begin(),2);
    cout << "\nLista Modificada (insert):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << " ";
    cout<< endl;


    auto it = lista.begin();
    it = next(it);      // el siguiente iterador, osea la posicion 1
    lista.insert_after(it, 3);  // En este caso insertara un valor despues de la segunda posicion
    //lista.insert_after(next(lista.begin()),3);        // es similar al anterior
    // Lo que hara es insertar un valor despues de la segunda posicion

    cout << "\nLista Modificada (insert):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;

    /// push_front: me sirve para insertar un valor en la primera posicion
    lista.push_front(0);

    cout << "\nLista Modificada (push_front):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;

    /// pop_front: me sirve para eliminar un valor en la primera posicion
    lista.pop_front();

    cout << "\nLista Modificada (pop_front):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;

    lista.push_front(3);

    cout << "\nLista Modificada (push_front):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;
    /// remove: lo que hace es eliminar todo los elementos que tengan ese valor
    lista.remove(3);

    cout << "\nLista Modificada (remove):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;

    /// remove_if: funcion lamba para calular los numeros pares, lo que hara es remover los elementos si son pares
    /// OBS: remove_if, siempre va recorrer todo el contenedor, osea valor por valor para corroborar si se cumple o no dicha condicion
    lista.remove_if([](int x){return x % 2 == 0;});

    cout << "\nLista Modificada (remove_if):" << endl;
    cout << "================================" << endl;

    for (int e: lista)
        cout << e << endl;


    /// find: me permite buscar la posicion de la variable que ponga, si es que no se encuentra me retornara la posicion final
    /// osea lista.end()
    return 0;

}