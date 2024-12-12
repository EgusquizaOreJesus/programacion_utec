#include "iostream"

using namespace std;

int main(){
    string digitos;
    int cheksum = 0;

    cout << "Digite su numero:";
    cin >> digitos;
    for (auto d: digitos) {
        cheksum += (d - '0');
    }
    cout << cheksum << endl;
    return 0;
}