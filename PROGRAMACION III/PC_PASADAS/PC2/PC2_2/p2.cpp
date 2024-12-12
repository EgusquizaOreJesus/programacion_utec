#include "iostream"



int foo ( int a , int b ) {
    while ( b > 0) {
        int q = a / b ;
        int r = a - q * b ;
        a = b ;
        b = r ;
    }
    return a ;
}
