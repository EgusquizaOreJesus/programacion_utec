#include "function.h"

using namespace std;

// ALGORITMO DE INSERTION SORT - CON VECTOR
void insertion_sort(vector<int> &A){
    for (int j = 1; j < A.size(); ++j) {
        int key = A[j];
        int i = j-1;
        while (A[i] > key && i>=0){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i + 1] = key;
    }
}

void insertion_sort_dec(vector<float> &A) {
    for (int j = 1; j < A.size(); ++j) {
        float key = A[j];
        int i = j-1;
        while (A[i] > key && i>=0){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i + 1] = key;
    }
}

// creando vector random enteros entre a y b
void crear_vector(vector<int> &A, int n, int a, int b){
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        A.push_back(rand()%b + a);
    }
}



// creando vector random decimales entre a y b
void crear_vector_dec(vector<float> &A, int n,int a, int b){
    srand(time(nullptr));
    random_device rd;
    uniform_real_distribution<float> dist(a, b);  //me indica que el rango de valores que ira el numero decimal
    for (int i = 0; i < n; ++i) {
        A.push_back(dist(rd));
    }
}

// Imprimir vector
void print_seq(vector<int> A){
    for(auto k:A){
        cout << k << " ";
    }
    cout << endl;
}

void print_seq_dec(vector<float> A) {
    for(auto k:A){
        cout << setprecision(5) <<k << " ";
    }
    cout << endl;
}

// Eliminar numero repetido de un vector
// Creo una funcion que retorne un vector
vector<int> eliminar_rep(vector<int> A){
    vector<int> out;
    int temp = A[0];
    for (int i = 1; i < A.size(); ++i) {
        if (temp != A[i]){
            out.push_back(A[i]);
            temp = A[i];
        }
    }
    return out;
}
