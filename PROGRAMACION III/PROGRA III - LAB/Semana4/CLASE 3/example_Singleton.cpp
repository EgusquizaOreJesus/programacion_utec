#include "iostream"
#include "string"

using namespace std;

/// Singleton
/// Su objetivo es tratar de crear una clase que no se pueda instanciar mas de una vez
// El Singleton lo que me evita es que yo pueda crear dos instancias de una misma clase

class A{
    string value;

public:
    A(const string& val_):value(val_){}
    string get_name(){return value;}

};

class B{
public:
    // Metodo de Instancia
    // yo solamente puedo acceder a este metodo si instancio una clase B
    void mostrar_mensaje(){
        cout << "Hola UTEC\n";
    }

    // Metodos de clase
    // Se diferencia colocando la palabra "static"
    /// Dicho static lo que hace es hacer este metodo global pero de la clase
    static void mostrar_mensaje2(){
        cout << "Hola UTEC2\n";
    }
};

/// que signfica este static?
// Significa que esta variable solo tiene validez en este archivo
// Es global solamente para el archivo,  si no tuviera static
// Seria global total, todos los archivos que incluyan este archivo lo van a ver
static int y = 10;


/// ¿Que es Instanciar? --> Se refiere a crear un objeto

int main(){
    /// Aqui  estoy creando dos instancias del mismo objeto
    A a1 = A("Hola UTEC");      // Instancia 1
    A a2 = A("Hola CS");        // Instancia 2

    cout << a1.get_name() << endl;
    cout << a2.get_name() << endl;
    // Y lo que ocurre aqui es que esta clase la estoy creando dos veces
    /// EL SINGLETON LO QUE ME EVITA ES ESTO, lo que va hacer es crear más de 2 veces esa clase
    /// Para ello
    // 1. Tengo que evitar el uso del constructor, para ello lo que se hace normalmente es colocar el constructor de forma privada
    // 2. Tengo que buscar algun mecanismo que me permita crearlo sin utilizar el constructor, para eso utilizo una alternativa
    // que me permita instanciar el objeto si no existe o llamar el objeto existente si este objeto existe
    /// PARA ELLO UTILIZO LOS METODOS ESTATICOS


    /// Metodo de Instancia:
    /// SOLO ASI PUEDO ACCEDER A ESTE METODO
    /// ESTE TIPO DE METODO SE LLAMA:
    /// Metodo de Instancia, porque la unica forma de llamar a este metodo es instanciando o creando una clase
    B b;
    b.mostrar_mensaje();


    /// Metodo de Clase:
    /// Porque no necesito instanciar o crear una clase para acceder a dicho metodo
    /// Puedo llamarlo asi:
    B::mostrar_mensaje2();      // NO NECESITO INSTANCIAR

    return 0;
}

/// ACORDAR:
/// En c++ hay la sobrecarga de muchos operadores:

/// UTILIZO EL OPERADOR * PARA:
// De-referencia
// Punteros
// Multiplicar
/// osea * <- esta sobrecargado (varios significados)

/// const tiene varios significados tambien
const int x = 10;                       // NO PUEDO CAMBIAR SU VALOR
const int* ptr1 = nullptr;              // El valor que guarda el puntero es constante
int const* ptr2 = nullptr;              // LO MISMO -> El valor que guarda el puntero es constante
int* const ptr3 = nullptr;              // La direccion del puntero es constante

/// static --> tambien tiene varios significados:


