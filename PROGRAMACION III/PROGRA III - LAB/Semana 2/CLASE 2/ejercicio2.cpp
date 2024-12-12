#include <iostream>
#include <math.h>

using namespace std;

template<int n=2, typename T=int>   //template no tipo y tipo con valor y tipo de variable por defecto
class Polinomio{
public:
    void print(){
        for (int i = 0; i <= n; ++i) {
            T num = rand()%1001 - 500;      //generando un numero aleatorio entre -500 a 500
            T num_def = num/100;
            if (num > 0 && i > 0){
                cout << " + ";
            }
            if (num_def != 0){
                cout << num_def;
            }
            if (i<n && num != 0){
                cout << "x^" << n-i;
            }
        }
        cout << endl;
    }
};


int main(){
    srand(time(NULL));
    Polinomio<3, float> pol1;   //reemplazan a los parametros por defecto
    pol1.print();       // Resultado: 0.17x^3+2.9x^2+3.1x^1+3.8

    Polinomio<4> pol2;  // aqui me arroja un polinomio de grado 4, y como no puse el otro parametro de tipo, se pondra el tipo por defecto (int)
    pol2.print();       // Resultado: -4x^4-2x^30x^2+3x^1-2

    Polinomio pol3;     // como no puse ningun parametro, se pondra el parametro por defecto
    pol3.print();       // Resultado: 0x^2+1x^1-3
    return 0;
}