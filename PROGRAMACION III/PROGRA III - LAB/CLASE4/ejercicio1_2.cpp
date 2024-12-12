#include "matrix.h"

using namespace std;

int main(){
    matrix2 m1(4,3);
    cout << m1 << endl;

    // Copia
    matrix2 m2 = m1;

    cout << m2 << endl;
    matrix2 m3 = m1 + m2;

    cout << m3 << endl;
    return 0;
}