#include <iostream>
#include "array"
#include "vector"
#include "deque"
#include "tuple"

using namespace std;
// 3 TIPOS DE PARAMETROS DE TEMPLATES:
// PARAMETROS TIPOS
template<typename T>
T sumar1(T a, T b){return a+b;}

// PARAMETRO TIPO Y CON PARAMETRO NO TIPO
// su uso se puede ver en la clase array que necesiriamente tengo que poner explicimiento el tipo de variable y su tamaño
template<typename T, int size>
class Array{
};
void ejemplo_uso_de_parametro_no_tipo(){
    array<int, 4> arr = {1,2,3,4};
    for (auto i:arr)
        cout << i << " ";
    cout << endl;
}
// PARAMETRO TIPO Y UN PARAMETRO TEMPLATE DE TEMPLATE
// lo que me dice template<typename ...> typename Container>
// 1° template<typename ...> usualmente se pone ...
// lo que me dice es que el template que esta aca dentro
// tiene una lista de parametros de template variados, cuando no sabes cuantos parametros va tener
// si sabes cuantos tipos tiene normal puedes ponerlo
template<typename T, template<typename ...> typename Container>
//TIENE 2 PARAMETROS
// - Parametro tipo
// - Parametro template de template
Container<T> create(){
    return Container<T>{};
}
void ejemplo_uso_de_parametro_template_template(){
    auto v = create<string,vector>();
    v.push_back("Jose");
    v.push_back("Maria");
    for (auto i:v)
        cout << i << " ";
    cout<<endl;
    auto d = create<string,deque>();
    d.push_back("Jose");
    d.push_back("Maria");
    for (auto i:d)
        cout << i << " ";
    cout<<endl;
}


// cuando sabes los parametros que tiene el template interno, lo pones
// Aqui tiene los 3 tipos de parametros
template<typename T,size_t sz, template<typename,size_t> typename Array>
//TIENE 3 PARAMETROS
// - Parametro tipo
// - Parametro no tipo
// - Parametro template de template
Array<T,sz> create_array(){
    return Array<T,sz>{};
}
void ejemplo_uso_de_parametro_template_template_cantidad_fija(){
    auto a1 = create_array<int,4,array>();
    for (auto i:a1)
        cout << i << " ";
    cout<<endl;
    auto a2 = create_array<string,3,Array>();
}

// TEMPLATE DE FUNCIONES
// PARAMETROS SIMPLES
template<typename T>
auto sumar(T a, T b){return a+b;}   //dicha funcion tiene muchas limitantes

// PARAMETROS COMPLEJOS - VARIADIC TEMPLATE
// En estos casos tiene una lista variada de parametros de distintos TIPOS
// En estos casos se utilizan los ...
// Y en este caso lo que hace los ..., es poder utilizar varios TIPOS

// En este caso son PARAMETROS TIPOS - COMPLEJO
// VARIADIC TEMPLATE DE TIPOS
template<typename ... Ts>
auto funcion(){
    cout << __PRETTY_FUNCTION__  << endl;
}

// Tambien puede hacerse con PARAMETROS NO TIPOS - COMPLEJO
// VARIADIC TEMPLATE DE NO TIPOS
template<int ... Ts>
auto funcion2(){
    cout << __PRETTY_FUNCTION__  << endl;
}

// VENTAJAS DE LOS VARIADIC TEMPLATES
// LA ESTRUCTURA <typename ... Ts> or <int ... Ts>
// me permite manipular una coleccion de TIPOS O NO TIPOS


// hare la funcion sumar con parametros variadic template
// para que asi pueda sumar variables de distintos tipos
template<typename ...Ts>            // ... Ts --> Empaqueta los tipos
auto sumar2(Ts... ts){       // Ts ... --> Aqui estoy desempaquetando, osea abriendo esa caja para ver uno por uno los tipos de valores que son
    cout << __PRETTY_FUNCTION__  << endl;
    // y para acceder a sus valores,
    // Una forma es mediante "tuples"
}
// PARA ACCEDER A LOS VALORES DE UN CONJUNTO DE VARIABLES DE DISTINTOS TIPOS,
// Se puede realizar de la siguiente forma:
template<typename T, typename ...Ts>    // el primer valor no esta empaquetado, y el resto si
auto print(T t, Ts... ts){
    cout << __PRETTY_FUNCTION__  << endl;
    cout << t << endl;                  //toma el primer valor, y el resto de valores los mantiene empaquetado
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// LA IMPLEMENTACION COMPLETA PARA IMPRIMIR VALORES DE DIFERENTES TIPOS ES:

// 1° CREAR UN TEMPLATE DE FUNCIONES CON RECURSIVIDAD
// 2° CREAR UNA FUNCION REGULAR PARA SOBRECARGA DICHA FUNCION EN CASO DE QUE NO IMPRIMA NADA

//LO QUE HAREMOS ES APLICAR LA RECURSIVIDAD PARA ACCEDER A TODOS LOS VALORES
// hay dos formas de definir una recursividad
// Haremos la forma tradicional
// 1° definimos una condicion base
// 2° una condicion recursiva
template<typename T, typename ...Ts>
auto print2(T t, Ts... ts){
    //cout << __PRETTY_FUNCTION__  << endl;
    // CONDICION BASE (utilizaremos el sizeof...) el sizeof... lo que hace es contar la cantidad de elementos que tiene el paquete
    if constexpr (sizeof ...(ts)==0){
        cout << t << " " <<__PRETTY_FUNCTION__ <<" - condicion base"<<endl;
    }
    // Condicion RECURSIVA
    else{
        cout << t << " " <<__PRETTY_FUNCTION__ <<endl;
        // y vuelvo a llamar a la funcion, pero solamente desempaqueto el ts..., y asi poco a poco se va achicando el arreglo
        print2(ts ...);
    }
    // si te das cuenta el T va cambiando mientras el paquete se va achicando
    // pero esta funcion recursiva de template
    // TIENE SU LIMITANTE, QUE FALLA SI ES QUE COLOCO print2() vacio, porque de todas maneras esta funcion esta esperando un T
    // Tiene que tener un parametro
    // PARA SOLUCIONARLO CREO UNA FUNCION REGULAR SIN PARAMETROS
    // PARA ASI CUANDO NO DETECTE NADA VAYA A DICHA FUNCION, OSEA ESTOY SOBRECARGANDO LA FUNCION
}

auto print2(){};    // estoy sobrecargando dicha funcion, para que cuando no encuentre nada, utilice dicha funcion regular

/////////////////////////////////////////////////////////////////////////////// TODO ESO ES LA IMPLEMENTACION


//////////////////////////////////////////////////////////////////////////////////////
//OTRA IMPLEMENTACION PARA PRINTEAR VALORES DE DIFERENTES TIPOS,
// ES USANDO FOLDING EXPRESSIONS
// Y ESTA FORMA ES MUCHA MAS COMPACTA
template<typename T,typename ... Ts>
auto print3(T t,Ts... ts){
    cout << t << " ";                 // AQUI TOMA EL PRIMER VALOR
    (..., print3(ts));      // AQUI HACE EL PROCESO DE RECURSIVIDAD --> ESTO ES UN FOLD EXPRESSION
}
// PARA EVITAR ERROR CUANDO NO HAY DATOS QUE PRINTEAR, HAGO UNA SOBRECARGA A ESTA FUNCION REGULAR
auto print3(){};
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// OTRA IMPLEMENTACION AUN MÁS COMPACTA SERIA
// En este ya no NECESITO un parametro adicional
// SIGO USANDO FOLD EXPRESSION
template<typename ... Ts>
auto print4(Ts ... ts){
    (cout << ... << ts);    //FOLD EXPRESSION
}
// PERO SU DESVENTAJA ES QUE IMPRIME TODO JUNTO
// PARA SOLUCIONARLO EN EL CASO DE PRINTEAR SERIA:
template<typename ... Ts>
auto print5(Ts ... ts){
    //(cout << ... << ts);    //FOLD EXPRESSION
    ((cout << ts << " "),...);
}

// Ahora COMO SE LEE ESE FOLD EXPRESSION


//////////////////////////////////////////////////////////////////////////////////////



int main() {
    //ejemplo_uso_de_parametro_template_template();
    //ejemplo_uso_de_parametro_template_template_cantidad_fija();

    cout << sumar(2,3) << endl; // llamada implicita (deduce los valores)
    //cout << sumar(2,2.4);// NO PUEDO HACER ESTO, NO SABE QUE T QUIERO, NO SABE CUAL ELEGIR, ENTERO O DOUBLE
    //PARA EVITAR ESE CONFLICTO, EL CASO MAS SENCILLO ES UTILIZAR LA DECLARACION DEL TIPO EXPLICITAMENTE
    cout << sumar<double>(2,2.4) << endl;   // esta forma me fuerza a poner un tipo ESPECIFICO, y descubro que es un template
    // Y EN TERMINOS GENERALES: SE TIENE QUE EVITAR QUE SE USE

    // TIPOS
    funcion<int,float,string,bool,bool>();
    funcion<int,float,bool,bool>();
    funcion<int,float>();
    funcion<>();
    funcion2<1,2,3,4>();    //NO TIPOS
    sumar2(1,2.0f,3.0,'c');

    print(1,2.0f,3.0,'c');  //aqui toma el primer valor y el resto de valores lo

    print2(1,2.0f,3.0,'c');
    print2();
    print3(1,2.0f,3.0,'c');
    print3();
    cout << endl;
    print4(1,2.0f,3.0,'c');
    print4();                   //DE LA ULTIMA FORMA ES MAS EFICIENTE QUE LAS DEMAS, PORQUE ME INDICA QUE ESTO NO LO VA A USAR
    // OMITO PONERLE SOBRECARGA A LA FUNCION
    cout << endl;
    print5(1,2.0f,3.0,'c');
    print5();
    return 0;
}
