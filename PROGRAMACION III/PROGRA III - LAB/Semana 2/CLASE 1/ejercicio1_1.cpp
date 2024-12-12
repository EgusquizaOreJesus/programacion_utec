#include "iostream"

using namespace std;

template<class T>
T sumatoria(T x, int n){
    T sum = 1;
    for (int i = 1; i <=n ; ++i) {
        sum += i*x;
    }
    return sum;
}

template<class T1, class T2, class T3>
T1 foo(T1 x, T2 y, T3& z){
    z = x/y;
    return x*y;
}


int main(){
    // Ejercicio 1.1
    cout << sumatoria(3.2,3) << endl;

    // Ejercicio 1.2
    float z;
    cout << foo(1.2,2,z) << endl;
    cout << z << endl;
    cout << "*******************" << endl;
    cout << foo(5,2,z) << endl;
    cout << z << endl;
    return 0;
}