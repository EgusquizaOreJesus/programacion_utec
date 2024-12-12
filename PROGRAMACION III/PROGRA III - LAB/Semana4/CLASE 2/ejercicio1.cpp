#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <assert.h>

using namespace std;
/// Comparar los algoritmos insertion_sort y  bubble_sort, e indicar cuál es el más eficiente para ordenar.

template<class It>
void print_container(It begin, It end){
    for (auto it=begin; it!=end; it++)
        cout << *it << " ";
    cout << endl;
}


template<class T>
void insertion_sort(vector<T>& A){
    for(std::size_t j = 1; j < A.size(); j++){
        T key = A[j];
        int i = j-1;

        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

template<class T>
void is_sorted(vector<T> A){
    for(std::size_t j = 1; j < A.size(); j++){
        assert(A[j-1] <= A[j]);
    }
}


int main(){
    srand((unsigned)time( NULL ) );
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    vector<double> A(20000);
    vector<double> B(20000);
    generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    B = A;
    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio
    insertion_sort(A);
    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin
    is_sorted(A);

    std::chrono::duration<double, std::milli> t2 = fin - inicio;
    cout << "insertion_sort (time) = " << t2.count() << "ms" << endl;
    return 0;
}
