#include "iostream"
#include "vector"
#include "list"


using namespace std;
template <typename ForwardIterator>
double sumarizar (ForwardIterator primero, ForwardIterator ultimo, double T)
{
    for (; primero != ultimo; ++primero) {
        T += *primero;
    }
    return T;
}


int main(){
    // Contenedor
    std::list<double> lst = {10.5, 20.4, 30.2, 40.5, 50.9, 60.5};
    cout << "Total: " << sumarizar(begin(lst), end(lst), 0) << endl;
// Calcular la mitad de valores inferior
    auto last_it = next(begin(lst), size(lst) / 2);
    cout << "Sumatoria de la mitad: " << sumarizar(begin(lst), last_it, 0) << endl;
}