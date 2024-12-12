#include "Polinomio.h"

int main(){
    Polinomio poli1(5);
    Polinomio poli2(6);

    Polinomio sum = poli1 + poli2 ;
    cout << poli1 << " : poli1 " << endl ;
    cout << poli2 << " : poli2 " << endl ;
    cout << sum << " : poli1 + poli2 " << endl ;;
    return 0;
}