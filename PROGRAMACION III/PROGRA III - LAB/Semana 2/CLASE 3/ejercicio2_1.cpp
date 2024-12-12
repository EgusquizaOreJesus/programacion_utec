#include "iostream"

using namespace std;

template<typename T>
void SwapVal(T& a, T& b){
    cout << "INTERCAMBIANDO VALORES" << endl;
    T temp = a;
    a = b;
    b = temp;
}

// REALIZANDO UNA ESPECIALIZACION AL TIPO FLOAT
template<>
void SwapVal(float & a, float& b){
    cout << "INTERCAMBIANDO VALORES (especializacion float)" << endl;
    float temp = a;
    a = b;
    b = temp;
}


// REALIZANDO UNA ESPECIALIZACION AL TIPO CHAR
template<>
void SwapVal(char& a, char& b){
    cout << "INTERCAMBIANDO VALORES (especializacion char)" << endl;
    char temp = a;
    a = b;
    b = temp;
}



int main(){
    int a = 3;
    int b = 2;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    SwapVal(a,b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    float p = 3.4, q = 1.5;
    cout << "p = " << p << ", q = " << q << endl;
    SwapVal(p, q);
    cout << "p = " << p << ", q = " << q << endl;

    char x = 'x', y = 'y';
    cout << "x = " << x << ", y = " << y << endl;
    SwapVal(x, y);
    cout << "x = " << x << ", y = " << y << endl;


    return 0;
}