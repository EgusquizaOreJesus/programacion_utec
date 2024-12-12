//
// Created by Jesus on 20/01/2023.
//

#include "function1.h"

INT_NO_NEGATIVE *crear_array(int size) {
    auto arr = new INT_NO_NEGATIVE[size];
    for (int i = 0; i < size; ++i) {
        int temp;
        std::cout << "numero:";
        cin >>  temp;
        cout << endl;
        arr[i] = temp;
    }
    return arr;
}

vector<INT_NO_NEGATIVE> crear_Vector(int size) {
    vector<INT_NO_NEGATIVE> vec;
    for (int i = 0; i < size; ++i) {
        int temp;
        std::cout << "numero:";
        cin >>  temp;
        cout << endl;
        vec.push_back(temp);
    }
    return vec;
}

void print_array(INT_NO_NEGATIVE* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(const vector<INT_NO_NEGATIVE> &vec) {
    for(auto t:vec){
        cout << t << " ";
    }
    cout << endl;
}

INT_NO_NEGATIVE find_mode_array(const INT_NO_NEGATIVE *arr, int size) {
    INT_NO_NEGATIVE mode;
    INT_NO_NEGATIVE maxRepeticiones = 0;
    INT_NO_NEGATIVE repeticiones = 0;
    for (int i = 0; i < size; i++){
        repeticiones++;
        if (arr[i] != arr[i+1] || i == size - 1){
            if (repeticiones > maxRepeticiones){
                maxRepeticiones = repeticiones;
                mode = arr[i];
            }
            repeticiones = 0;
        }
    }
    return mode;
}

INT_NO_NEGATIVE find_mode_vec(const vector<INT_NO_NEGATIVE> &vec) {
    INT_NO_NEGATIVE mode;
    INT_NO_NEGATIVE maxRepeticiones = 0;
    INT_NO_NEGATIVE repeticiones = 0;
    for (int i = 0; i < vec.size(); i++){
        repeticiones++;
        if (vec[i] != vec[i+1] || i == vec.size() - 1){
            if (repeticiones > maxRepeticiones){
                maxRepeticiones = repeticiones;
                mode = vec[i];
            }
            repeticiones = 0;
        }
    }
    return mode;
}

// ALGORITMO DE INSERTION SORT - ARRAY DINAMICO
void insertion_sort_array(INT_NO_NEGATIVE* arr, int size){
    for (int j = 1; j < size; j++) {
        INT_NO_NEGATIVE key = arr[j];
        int i = j - 1;
        while (arr[i] > key && i >= 0) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
// ALGORITMO DE INSERTION SORT - CON VECTOR
void insertion_sort_vector(vector<INT_NO_NEGATIVE> &A){
    for (int j = 1; j < A.size(); ++j) {
        INT_NO_NEGATIVE key = A[j];
        int i = j-1;
        while (A[i] > key && i>=0){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i + 1] = key;
    }
}