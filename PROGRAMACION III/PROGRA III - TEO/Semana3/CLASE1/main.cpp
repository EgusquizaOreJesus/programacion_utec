#include <iostream>
#include "vector"
#include "string"
#include "list"

using namespace std;



// PARA PODER IMPRIMIR LISTAS Y VECTORES O CUALQUIER TIPO
// ES NECESARIO CREAR UN TEMPLATE DE TEMPLATE, AHI SI SERA POSIBLE ITERAR SOBRE UNA LISTA DE ESA FORMA l[i]

// funcion para imprimir cualquier tipo de contenedor vector, pero no funciona para LISTAS OJO
template<typename T, template<typename ...>typename Container>
void imprimir(Container<T> cnt){
    for (int i = 0; i < cnt.size(); ++i) {
        cout << cnt[i] << " ";
    }
    cout << endl;
}

// usando esta forma de iterar valores de un contenedor
// es posible iterar valores de cualquier tipo de contenedor sea lista, vector, mapa, etc
template<typename T, template<typename ...>typename Container>
void imprimir2(Container<T> cnt){
    for (auto it = cnt.begin(); it!= cnt.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void ejemplo_iteradores(){
    vector<int> v = {10,20,30,40};
    list<int> l = {10,20,30,40};

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    // aqui eso no funciona para LISTAS
    /*
     *
    for (int i = 0; i < l.size(); ++i) {
        cout << l[i] << " ";
    }
    cout << endl;
     */
    // con esa funcion template de template si es posible iterar cualquier tipo de contenedor

    imprimir(v);
    // imprimir(l); sigue sin funcioanr para listas;

}

void ejemplo2_iteradores(){
    vector<int> v = {10,20,30,40};
    list<int> l = {10,20,30,40};

    // iterador de inicio
    auto it = v.begin();
    cout << *it << endl; // el it me muestra la direccion del primer elemento del vector, para saber su valor tengo que dereferenciar *
    *it = 100; // asi tambien puedo cambiar su valor
    //imprimir(v);

    // haciendo uso de la otra forma
    imprimir2(v);
    imprimir2(l);
}

int main() {
    vector<int> v = {10,20,30,40};
    list<int> l = {10,20,30,40};

    auto a = v.end();
    auto c = l.end();

    // Estas funciones son globales para cualquier tipo de contenedor funciona:
    cout << *prev(a,1) << endl;
    cout << *prev(c,1) << endl;

    return 0;
}
