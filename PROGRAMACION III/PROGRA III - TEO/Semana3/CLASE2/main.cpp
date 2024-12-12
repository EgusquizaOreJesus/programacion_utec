#include <iostream>
#include "vector"
#include "list"
#include "forward_list"

/// LIBRERIA ESTANDAR

using namespace std;

void ejemplo_funciones_iterador(){
    vector v = {10,20,30,40,50,60};         //GUIA DE DEDUCCION: Se deduce el tipo por los datos que tengo dentro del contenedor
    list l = {10,20,30,40,50,60};           // DEDUCE SI TODOS TIENEN EL MISMO TIPO
    forward_list f = {10,20,30,40,50,60};

    // OBS: Pero si yo quiero crear un vector de enteros vacio, ahi si tengo que poner su tipo explicitamente porque no sabra que deducir
    vector<int> v2;

    // sacando los iteradores de cada tipo de contenedor
    // Para el vector, su iterador se categoriza como random iterator
    auto r_iter = v.begin();

    // Para el list, su iterador se categoriza como bidireccional iterator
    auto b_iter = l.begin();

    // Para el forward_list, su iterator se categoriza como forward iterator
    auto f_iter = f.begin();

    // AVANZAR DE 2 EN 2:
    // Para el caso del vector si es posible pero para los demas NO SE PUEDE REALIZAR
    // En los iterator random SI SE PUEDE UTILIZAR ARITMETICA DE PUNTEROS:
    cout << *(r_iter + 2) << endl;
    // Pero para los demas casos NO LO ADMITE
    // cout << *(b_iter + 2) << endl;
    // cout << *(f_iter + 2) << endl;

    // SI YO QUISIERA AVANZAR ASI, NECESITARE USAR LAS FUNCIONES GLOBALES PARA LOS ITERADORES
    // Estas funciones son globales para cualquier tipo de contenedor funciona:

    // Si quiero avanzar de dos en dos, utilizo la funcion "next"
    cout << *next(r_iter,2) << endl;
    cout << *next(b_iter,2) << endl;
    cout << *next(f_iter,2) << endl;

    // Si quiero avanzar en sentido contrario, utilizo la funcion "prev"
    r_iter = next(r_iter,2);
    b_iter = next(b_iter,2);
    f_iter = next(f_iter,2);

    cout << *prev(r_iter,2) << endl;
    cout << *prev(b_iter,2) << endl;
    //cout << *prev(f_iter,2) << endl;            //OBS: Pero para el forward_list NO ES POSIBLE RETROCEDER

    // AHORA COMO SOLUCIONO EL PROBLEMA DE prev en un FORWARD LIST
    // Para ello hacemos uso de la funcion "distance"
    // medimos la distancia desde el begin hasta el valor que esta mi contenedor actual
    auto a = distance(begin(f),f_iter);
    auto b = 2;
    cout << *next(begin(f),a-b) << endl;

    for (auto it = begin(v); it != end(v) ; ++it) {
        // CON distance puedo saber la distancia o suindices de cada dato guardado en el contenedor
        cout << distance(begin(v),it) << " " << *it << endl;
    }

    // La funcion global advance es equivalente al ++
    r_iter = begin(v);
    r_iter++;
    cout << *r_iter << endl;
    r_iter += 2;
    cout << *r_iter << endl;

    // Para el caso de random es ACCESIBLE
    // Pero para otro tipo de iterador, es mas complejo por ello mejor usar el advance
    // Porque para estos casos de iteradores no existe el autoincremento += k, para ello es mejor usar advance que es equivalente
    // NO ES POSIBLE f_iter += 2;
    f_iter = begin(f);
    advance(f_iter,1);
    cout << *f_iter << endl;

    advance(f_iter,2);
    cout << *f_iter << endl;
}

void ejemplo_insert(){
    vector v =  {10,20,30,40};
    vector<int> v2;

    // Aca puedo utilizar un algoritmo copy para copiar un vector en otro
    // copy(v.begin(),v.end(),v2.begin());      // ESTE ALGORITMO VA FALLAR PORQUE LOS CONTENEDORES TIENEN QUE SER DE IGUAL TAMAÑO

    // Si tienen del mismo tamaño si es posible usar el copy
    vector<int> v3(4);
    copy(v.begin(),v.end(),v3.begin());
    for(auto item:v3){
        cout << item << " ";
    }
    cout << endl;

    // UNA SOLUCION PARA NO PONER EL TAMAÑO DEL VECTOR EN LA COPIA ES USAR "back_inserter"
    // Este back_inserter, hace un pushback internamente
    // Se puede observar que hace el mismo efecto pero sin necesidad de poner el mismo tamaño del vector que estoy copiando
    // ya que el back_inserter actua como un pushback, osea que adiciona un elemento al final
    /// Es mas eficiente porque en una sola linea copia valores de un vector a otro
    vector<int> v4;
    copy(v.begin(),v.end(), back_inserter(v4));
    for(auto item:v4){
        cout << item << " ";
    }
    cout << endl;


};


int main() {
    ejemplo_insert();

    return 0;
}
