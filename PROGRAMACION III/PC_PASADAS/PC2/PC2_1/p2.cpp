#include "iostream"

using namespace std;

/// COMPLEJIDAD ALGORITMICA
int foo ( int a , int b ) {
    int res = 1;
    while ( b > 0) {
        if ( b % 2 == 1)
            res = res * a;
        a = a * a ;
        b = b / 2;
    }
    return res ;
}

/// SUGERENCIA: trata de reducir la ecuacion
int foo2 ( int a , int b ) {
    int res;
    for(res=1 ;b>0;b = b/2){
        if ( b % 2 == 1)
            res = res * a;
        a = a * a ;
    }
    return res ;
}
int foo3 ( int a , int b ) {
    int res;
    for(res=1 ;b>0;b--){
        res*=a;
    }
    return res ;
}

/// INVARIANTE DE BUCLE:
///  b>0 siempre va cumplir
///  foo(a,b) == pow(a,b)
int main(){
    int res = foo(5,3);
    cout << res << endl;
    int res2= foo2(5,3);
    cout << res2 << endl;
    int res3= foo3(5,3);
    cout << res3 << endl;

}