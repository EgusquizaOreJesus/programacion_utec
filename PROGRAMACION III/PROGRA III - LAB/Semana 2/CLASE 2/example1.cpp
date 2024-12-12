#include <iostream>

using namespace std;



template<int n>
class A{
    int area = n * n;
public:
    void get_area(){cout << area << endl;}
};

template<int n = 3>     // un valor por defecto al valor n, osea si a n no le colocas ningun valor, este tomara por defecto el 3
class B{
    int area = n * 3;
public:
    void get_area(){cout << area << endl;}
};

template<auto k> // C++17       //El placeholder puede ser de cualquier tipo auto:
                                //auto, auto&, auto**
class C{};

int main(){
    A<5> a1;        // si no hay un valor por defecto, OBLIGATORIAMENTE NECESITAS DECLARAR LA VARIABLE EXPLICITAMENTE EN EL TEMPLATE NO TIPO
    a1.get_area();
    B b1;           // POR DEFECTO TIENE EL NUMERO 3
    b1.get_area();
    B<4> b2;        // Si declaro una variable explicitamente, TOMARA ESE VALOR Y NO EL QUE ESTA PUESTO POR DEFECTO
    b2.get_area();
    C<'a'> c1;
}