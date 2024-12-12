#include "iostream"

using namespace std;

// HAY DOS TIPOS DE PARAMETROS TEMPLATES
// PARAMETROS SIMPLES:
// template de funcion de un solo tipo
template<typename T>
auto sumar(T a, T b){
    cout << __PRETTY_FUNCTION__  << endl; //dicha funcion me va mostrar como fue el proceso de duccion del tipo de valor
    return a+b;
}
template<typename T1,typename T2>
auto sumar2(T1 a, T2 b){
    cout << __PRETTY_FUNCTION__  << endl;
    return a+b;
}

// PARAMETROS COMPLEJOS - Variadic Templates
// SI QUIERO SUMAR UN CONJUNTO DE VALORES VARIADOS,
// Coloco ... para definir que son una serie de tipos // ya no es un solo parametro es una coleccion de parametros
// Este es un parametro tipo, pero de una serie de tipos
// Y la ventaja es que puedo sumar una serie de variable de diferentes tipos
template<typename ...Ts>            // genera un Variadic Template
auto sumar3(Ts... ts){             // pongo asi porque quiero sumar un conjunto de valores
    // pero para poder sumar este conjunto de valores, ES NECESARIO UTILIZAR UNA ESTRUCTURA NUEVA LLAMADA:
    // folding expression
    cout << __PRETTY_FUNCTION__  << endl;
    return (... + ts);              // Fold expression
}



int main(){
    cout << sumar(10,20) << endl;     //El tipo T es deducido del tipo de valor
    cout << sumar(4.2,3.2) << endl;
    //cout << sumar(4.2,5) << endl;           // Aqui va fallar porque no lo va poder deducir, ya que en el primer
    // parametro T es un double y en el segundo parametro T es un entero, no sabra que retornar

    // Una forma de solucionarlo es definirlo explicitamente definir el parametro de template,
    // Y para este caso tendra dos argumentos la funcion, el primero sera definirle el tipo a T y el segundo argumento son los valores de la funcion
    // seria algo asi:
    cout << sumar<double>(4.2,5) << endl;  //aqui no falla
    // pero pierde precision si pongo
    cout << sumar<int>(4.2,5) << endl;  //aqui no falla


    // Otra forma es crear otra funcion sumar que contenga 2 parametros de tipo en el template, ahi si funcionaria
    // Pero no es la forma mas apropiada, lo mejor es ponerle explicitamente la definicion del parametro del template
    cout << sumar2(4.2,5) << endl;

    // Entonces hay dos formas de llamar a los templates:
    // 1. que lo deduzca a partir de los valores
    cout << sumar(3,2) << endl;
    // 2. Declaracion explicita de la definicion de T
    cout << sumar<double>(4.2,5) << endl;

    // Variadic template
    cout << "VAIRADIC TEMPLATE" << endl;
    cout << sumar3(10,5.5) << endl;
    cout << sumar3(10,4,3) << endl;
    cout << sumar3(10,4.2,3.3,6) << endl;

    return 0;
}