#include <iostream>

using namespace std;

template<typename T>
void init_array(T &arr);
template<typename T>
void init_array(T &arr,int k);
template<typename T>
void init_array(T &arr,int k, int p);
template<typename T>
void init_array(T &arr,int k, int f,int p);
// COMPLETO


// PREGUNTA 9;
int main() {
    double arreglo[] {0, 0, 0, 4, 5, 6};
    init_array(arreglo, 2, 8, 2);   // Se puede configurar el valor inicial (2)
    // valor siguiente al final (8) y
    // el paso (2)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 2 4 6 4 5 6
}
template<typename T>
void init_array(T &arr){

    int temp = 0;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=1;
    }
}
template<typename T>
void init_array(T &arr,int k){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=1;
    }
}

template<typename T>
void init_array(T &arr,int k, int p){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        arr[i] = temp;
        temp+=p;
    }

}

template<typename T>
void init_array(T &arr,int k, int f,int p){
    int temp = k;
    for (int i = 0; i < size(arr); ++i) {
        if (temp == f){ break;}
        arr[i] = temp;
        temp+=p;
    }
}