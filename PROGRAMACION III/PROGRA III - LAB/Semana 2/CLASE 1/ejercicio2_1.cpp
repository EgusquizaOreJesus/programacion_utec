#include "Numeros.h"


using namespace std;

int main(){
    Numeros obj(2.1, 3);
    cout << obj.sumar() << endl;
    cout << obj.resta() << endl;
    cout << obj.producto() << endl;
    cout << obj.division() << endl;



    return 0;
}