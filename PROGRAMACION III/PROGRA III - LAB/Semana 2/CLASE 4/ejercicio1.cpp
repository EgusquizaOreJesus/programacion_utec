#include "iostream"

using namespace std;

template<typename ... Ts>
auto suma(Ts... ts){
    return ((ts)+...);    //fold expression
}

template<typename ... Ts>
float promedio(Ts... ts){
    float s = suma(ts...);  //accedo al paquete empaquetado de suma
    return s/sizeof ...(ts);
    // acuerdate: sizeof ...(ts) --> me permite acceder al tamaño del paquete
}

int main(){
    cout << promedio(1) << endl;
    cout << promedio(1,3.2) << endl;
    cout << promedio(1,2,3,4,5) << endl;
    cout << promedio(3,3,-3-5,1.5,0) << endl;
    return 0;
}