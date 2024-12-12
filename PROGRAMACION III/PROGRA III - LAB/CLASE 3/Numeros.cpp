//
// Created by Jesus on 20/01/2023.
//

#include "Numeros.h"

Numeros::Numeros(SizeType tam) {
    tam_ = tam;
    arr = new int[tam_];
    std::random_device rd;
    std::uniform_int_distribution<int> dis(0,20); //numeros aleatorios entre 0 a 20
    for (int i = 0; i < tam_; ++i) {
        arr[i] = dis(rd);
    }
}

SizeType Numeros::tam() const {
    return tam_;
}

ostream &operator<<(ostream &os, const Numeros &arr) {
    for (int i = 0; i < arr.tam_; ++i) {
        os << arr.arr[i] << " ";
    }
    os << std::endl;
    return os;
}

int &Numeros::operator()(int i) {
    return arr[i];
}

int Numeros::operator()(int i) const {
    return arr[i];
}

SizeType Numeros::mode() {
    SizeType mode;
    SizeType maxRepeticiones = 0;
    SizeType repeticiones = 0;
    for (int i = 0; i < tam_; i++){
        repeticiones++;
        if (arr[i] != arr[i+1] || i == tam_ - 1){
            if (repeticiones > maxRepeticiones){
                maxRepeticiones = repeticiones;
                mode = arr[i];
            }
            repeticiones = 0;
        }
    }
    return mode;
}

int Numeros::max_element() {
    int max = arr[0];
    for (int i = 1; i < tam_; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void Numeros::insertion_sort_array() {
    for (int j = 1; j < tam_; j++) {
        int key = arr[j];
        int i = j - 1;
        while (arr[i] > key && i >= 0) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

