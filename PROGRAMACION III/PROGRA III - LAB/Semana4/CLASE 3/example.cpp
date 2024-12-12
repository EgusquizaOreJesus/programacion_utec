#include "iostream"
#include <memory>
using namespace std;

/// SINGLETON
/// ATRIBUTOS DE TIPO STATICO - ATRIBUTO DE CLASE
/// No necesito crear un objeto para llamar a este atributo
class A{
public:
    inline static string nombre;        // Atributo de clase
    string apellido;                    // Atributo no de clase

    /// Y ASI COMO TENGO ATRIBUTOS ESTATICOS
    /// TAMBIEN PUEDO TENER METODOS ESTATICOS - METODOS DE CLASE
    /// OJO, Dentro de los metodos ESTATICOS, solamente puedo llamar
    /// y trabajar con atributos o elementos declarados como ESTATICOS
    static string get_nombre(){return nombre;}
    static void set_string(const string& name){nombre = name;}
};

class B{
private:
    /// Atributo estaticos
    static string nombre;        // Atributo de clase
    // si no coloco inline, me obliga a ponerle una linea adicional afuera
    string apellido;                    // Atributo no de clase
public:
    /// METODOS DE CLASE - METODOS DE CLASE
    static string get_nombre(){return nombre;}
    static void set_string(const string& name){nombre = name;}
};


/// ¿Que sirve la palabra "inline"?
/// Si no coloco el inline en un atributo estatico, lamentablemente tendre que declararlo afuera
/// tendria obligatoriamente que declararlo afuera asi: sino fallaria
string B::nombre;

int main(){
    // No necesito crear un objeto para llamar a ese atributo
    // OJO: se puede acceder de esta manera porque estan declarados publicamente
    A::nombre = "PEDRO";

    // A::apellido = "Juarez"      //AQUI NO SE PUEDE ACCEDER AL APELLIDO
    // para acceder a ese elemento, SE NECESITARIA INSTANCIAR O CREAR UN OBJETO
    A a;
    a.apellido = "Juarez";

    /// Si los atributos estaticos estan declarados privados
    /// Para acceder a ellos y setearlos es necesario crear metodos estaticos publicos
    /// ejm: crearemos una clase B con metodos estaticos o metodos de clase publicos
    B::set_string("juan");
    cout << B::get_nombre();




    return 0;
}
