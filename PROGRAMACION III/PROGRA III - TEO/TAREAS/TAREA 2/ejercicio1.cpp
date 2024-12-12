#include "iostream"
using namespace std;
// COMPLETO

template<typename T=string>
T input(const string &com) {
    cout << com;
    T val;
    cin >> val;
    return val;
}

template<typename T=string>
T input() {
    T val;
    cin >> val;
    return val;
}
int main(){
    // Por default el template retorna un std::string
    auto text = input();
    auto entero = input<int>("Ingrese un numero:");
    auto real = input<double>("Ingrese un numero:");
    std::cout << "El texto es: " << text << endl;
    std::cout << "El entero es: " << entero << endl;
    std::cout << "El real es: " << real << endl;


    return 0;
}