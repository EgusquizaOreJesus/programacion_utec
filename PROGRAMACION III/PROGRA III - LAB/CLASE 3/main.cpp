#include <iostream>
//  LABORATORIO 2A
using namespace std;

int duplicarDigito(int digito){
    int digitoDuplicado = digito * 2;
    int sum;

    if (digitoDuplicado >= 10)
        sum = 1 + digitoDuplicado % 10;
    else
        sum = digitoDuplicado;
    return sum;
}

int main(){
    string digito;
    int checksum = 0;

    cout << "Ingresar un numero de 16 digitos: ";
    cin>> digito;

    for (int pos=1; pos <= digito.length(); pos++){
        if (pos % 2 != 0)
            checksum += digito[pos-1] - '0';
        else
            checksum += duplicarDigito(digito[pos-1] - '0');
        cout << checksum << endl;
    }


    cout << "El checksum es: " << checksum << ".\n";

    if (checksum % 10 == 0)
        cout << "El checksum es divisible entre 10. Es valido.\n";
    else
        cout << "El checksum no es divisible entre 10. No es valido\n";

    return 0;
}