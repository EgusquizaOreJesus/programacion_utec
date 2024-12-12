#include "function1.h"
#include "Numeros.h"


int main(){
    Numeros arr(100);
    //cout << arr.tam() << endl;
    cout << arr;
    arr.insertion_sort_array();
    cout << arr;
    cout << arr.mode();



    return 0;
}

// EJERCICIO 1
/*
     auto arr = crear_array(10);
    print_array(arr,10);
    insertion_sort_array(arr,10);
    print_array(arr,10);
    cout << "Su moda del arreglo es: " << find_mode_array(arr,10) << endl;

    vector<INT_NO_NEGATIVE> vec = crear_Vector(10);
    print_vector(vec);
    insertion_sort_vector(vec);
    print_vector(vec);
    cout << "Su moda del vector es: " << find_mode_vec(vec) << endl;

    delete[] arr;



 */