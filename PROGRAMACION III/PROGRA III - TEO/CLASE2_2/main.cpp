#include <iostream>

using namespace std;
//
class A{
    int a = int {}; // incializo los atributos en nulo
    public:
    A() = default; //CONSTRUCTOR POR DEFECTO
    // si no pusiera el constructor por defecto, dicho constructor por parametro anula si es que declaras por defecto
    // CONSTRUCTOR CON PARAMETROS
    A(int a): a{a} {};  // a(a) {}; --> el constructor por parametro puede declararse asi tambien A(int a): a(a){};

    // metodo get
    // ahora si pongo el "nodiscard" lo que haria es alertarme que un valor no esta siendo usado
    [[nodiscard]] int get() const {return a;}
    // coloco el "const",para poder habilitar y que se pueda ejecutar un metodo cuando el objeto es constante, NECESARIAMENTE
    // SE DEBE COLOCAR LA PALABRA "const", asi ESTE METODO SERA VALIDO PARA OBJETOS CONSTANTES O NO CONSTANTES, FUNCIONA PARA AMBOS

    // OBS: en los casos de gets o metodos que se comporten como gets, SIEMPRE UTILIZAR EL "const"

    // Estos operadores () vamos a sobrecargarlo para que funcione como un set y get.
    int& operator() (){return a;}           // Equivalente al set, aqui se retorna una referencia de "a", y para el caso del set si es necesario poner "&"
    int operator() () const {return a;}     // Equivalente al get
};


int main() {
    A a1; //declaro por defecto, si no esta el CONSTRUCTOR POR DEFECTO, esto me saldria ERROR
    A a2(10); //declaro con parametros

    a1.get(); // te das cuenta que esta linea no sirve para nada, y para evitar este tipo de errores y que el compilador me alerte
    // que estoy cometiendo este error se pone "nodiscard", y eso es la utilidad del nodiscard para alertar que esto esta incorrecto
    cout << a1.get() << endl;
    cout << a2.get() << endl;

    const A a3(20);
    cout << a3.get() << endl;

    // Con la sobrecarga del operador (), el getter lo puedo utilziar asi:
    cout << a1() << endl;
    cout << a2() << endl;
    // Con la sobrecarga del operador (), el setter lo puedo utilizar asi:
    a1() = 30; // esto es equivalente a a1.set(30)

    cout << a1() << endl;

    return 0;
}
