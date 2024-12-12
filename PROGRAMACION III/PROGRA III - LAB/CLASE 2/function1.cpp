//
// Created by Jesus on 14/01/2023.
//

#include "function1.h"

bool es_primo(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i == 0){
            return false;
        }
    }
    return true;
}

vector<int> vector_primo_dsCrifras(){
    vector<int> primos;
    for (int i = 10; i <100 ; ++i) {
        if (es_primo(i)){
            primos.push_back(i);
        }
    }
    return primos;
}
void print_vector(vector<int> A){
    for(auto a:A){
        cout << a << " ";
    }
    cout << endl;
}

// ALGORITMO DE ORDENAMIENTO PARA UN ARRAY DINAMICO
void insertion_sort(int* A, int n){
    for (int j = 1; j < n; j++) {
        int key = A[j];
        int i = j - 1;
        while (A[i] > key && i >= 0) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void print_array(int *A, int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

}
