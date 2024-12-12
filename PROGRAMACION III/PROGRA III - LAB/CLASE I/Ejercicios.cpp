#include "function.h"

int main(){
    // EJERCICIO1
    cout << "EJERCICIO 1" << endl;
    vector<int> A;
    crear_vector(A,30,1,100);
    print_seq(A);
    insertion_sort(A);
    print_seq(A);
    cout << endl;

    // EJERCICIO2
    cout << "EJERCICIO 2" << endl;
    vector<float> B;
    crear_vector_dec(B,10,0,1);
    print_seq_dec(B);
    insertion_sort_dec(B);
    print_seq_dec(B);
    cout << endl;

    // EJERCICIO3
    cout << "EJERCICIO 3" << endl;
    vector<int> C;
    crear_vector(C,30,1,20);
    print_seq(C);
    insertion_sort(C);
    print_seq(C);
    vector<int> D = eliminar_rep(C);
    print_seq(D);
    return 0;
}