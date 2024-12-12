#include <iostream>
#include "random"

using namespace std;

template<int n = 2>     // template no tipo con valor por defecto, cuando no se declare un valor explicitamente, ESTA FUNCION TOMARA EL VALOR POR DEFECTO
class Polinomio{
public:
    void print(){
        random_device rd;
        uniform_int_distribution<int> dis(1,10);
        for (int i = n; i >= 1; --i) {
            cout << dis(rd) << "x^" << i << " + ";
        }
        cout << dis(rd) << endl;
    }
};

int main(){
    Polinomio<4> pol1;
    pol1.print();       // Resultado: 3x^4 + 6x^3 + 7x^2 + 5x^1 + 3

    Polinomio pol2;
    pol2.print();       // Resultado: 5x^2 + 6x^1 + 2
}
