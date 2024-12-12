#include <iostream>
#include <math.h>

using namespace std;

// funcion de template con un tipo de dato por defecto
template<class T = int>     // tipo de variable por defecto
T raiz(int n){
    T num = n;
    return sqrt(num);
};

// si la funcion fuera auto, no es necesario declararle por defecto:
template<class T>     // tipo de variable por defecto
auto raiz2(T n){
    T num = n;
    return sqrt(num);
};
int main(){
    cout << raiz<float>(3) << endl; // Resultado: 1.73205
    cout << raiz<int>(3) << endl;   // Resultado: 1
    cout << raiz(5) << endl;        // Resultado: 2     // si no lo declaro explicitamente lo tomara el valor por defecto a "int"

    cout << raiz2<float>(3) << endl;
    cout << raiz2<int>(3) << endl;
    cout << raiz2(5) << endl;
}

