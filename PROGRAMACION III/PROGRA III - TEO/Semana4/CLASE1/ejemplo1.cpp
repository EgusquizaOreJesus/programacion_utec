#include "iomanip"
#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"

using namespace std;

bool EsPrimo(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i==0){
            return false;
        }
    }
    return true;
}

template< typename Iterator_i,typename Iterador_out,typename collab>
void copyif(Iterator_i start, Iterator_i stop,Iterador_out i_out, collab fn);
bool esMultiplo(int x,int base){
    return x%base==0;
}
/// Para poder poner una funcion collab con más parametros como entrada
/// Una solucion es:
/// Utilizar template con argumento un tipo entero que representar el multiplo al que quiero sacar sus valores
template<int n>
bool esMultiplo(int x){
    return x%n==0;
}


/// otra solucion seria usar "lambda", eso se haria en la misma funcion copyif

/// Y UNA CUARTA SOLUCION ES USANDO functor, que son clases que se comportan como funcion

/// functor: CLASE QUE SE COMPORTA COMO FUNCION ES EQUIVALENTE "lambda"
/// Para que funcione como funcion, hacemos sobrecargar al operador ()
class Multiplo{
    int base;
public:
    explicit Multiplo(int base_):base(base_){};     // Esto es equivalente al captcher [] --> constructor

    bool operator()(int iter) const{return iter%base==0;}



};
void ejemplo_copyif() {
    vector v = {10, 20, 30, 40, 7, 3};
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    vector<int> v6;

    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    /// LO MALO DE DICHA FUNCION ES QUE SOLO ACEPTARA UN PARAMETRO COMO ENTRADA DE LA FUNCION
    copyif(v.begin(), v.end(), back_inserter(v2), EsPrimo);
    //Imprimo los valores que se encuentran en el vector:
    for_each(v2.begin(), v2.end(), [](int x) { cout << x << " "; });
    cout << endl;

    /// PRIMERA SOL: utilizando template de funciones:
    /// Copiamos todos los elementos que sean multiplos de tres:
    copyif(v.begin(), v.end(), back_inserter(v3), esMultiplo<3>);
    //Imprimo los valores que se encuentran en el vector:
    for_each(v3.begin(), v3.end(), [](int x) { cout << x << " "; });
    cout << endl;

    /// OTRA SOLUCION PARA COPIAR LOS MULTPLICOS DE  x  DE UN VECTOR EN OTRO es USANDO "lambda"
    /// EN ESTE CASO COPIAREMOS SOLAMENTE LOS ELEMENTOS QUE SON MULTIPLOS DE 3:
    copyif(v.begin(), v.end(), back_inserter(v4), [base = 3](auto x) { return x % base == 0; });
    //Imprimo los valores que se encuentran en el vector:
    for_each(v4.begin(), v4.end(), [](int x) { cout << x << " "; });
    cout << endl;

    /// OBS: si quisiera que la base este designada afuera del copyif en los [] poner [base] o [=]
    /// Cuando pones [=], lo que hace es acceder a las variables gloables en solo lectura
    /// Cuando pones [&], accede a las variables en lectura y escritura
    // ejm:
    int base = 5;

    // copiaremos los elementos que sean multiplos de 5:
    copyif(v.begin(), v.end(), back_inserter(v5), [=](auto x) { return x % base == 0; });
    //Imprimo los valores que se encuentran en el vector:
    for_each(v5.begin(), v5.end(), [](int x) { cout << x << " "; });
    cout << endl;

    /// PERO HAY UN TERCER TIPO DE SOLUCION, QUE ES UTILIZANDO FUNCIONES PARCIALES
    /// Para ello primero incluimos la libreria "functional"
    /// Lo que hace funciones parciales, es convertir una funcion a otra funcion, es como un convertor
    /// Voy a crear una funcion a partir de otra funcion, y para ello hacemos uso de la funcion bind
    /// bind: toma la funcion generica y a partir de aqui le coloca de acuerdo a lo que yo quiero
    /// un valor al primer parametro



    /// Y como ultima y CUARTA SOLUCION ES UTILIZANDO functor
    // Es el predecesor del lambda
    /// El functor es basicamente una clase, pero que se comporta como una funcion
    /// Copiamos los multiplos de 3
    copyif(v.begin(), v.end(), back_inserter(v6),   Multiplo(3));
    //Imprimo los valores que se encuentran en el vector:
    for_each(v6.begin(), v6.end(), [](int x) { cout << x << " "; });
    cout << endl;

}



int main(){
    ejemplo_copyif();


    return 0;
}


/// VAMOS A CREAR NUESTRO PROPIO copy_if
// usualmente ese copy_if es un algoritmo que se declara como template
// no retorna nada

// Iterador que ingresa : Iterador_i
// Ierador que sale: Iterador_out
// collab: funcion para condicionar la copia para ciertos elementos

// CASI ASI FUNCIONA LA FUNCION copy_if
template< typename Iterator_i,typename Iterador_out,typename collab>
void copyif(Iterator_i start, Iterator_i stop,Iterador_out i_out, collab fn){
    for(auto iter= start; iter!= stop; iter++){
        if (fn(*iter)) {
            i_out = *iter;
            ++i_out;
        }

    }
}


