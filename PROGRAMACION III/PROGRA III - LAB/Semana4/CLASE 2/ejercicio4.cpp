#include "iostream"
#include "vector"
#include "algorithm"
#include "iomanip"
#include <assert.h>
#include "chrono"

using namespace std;

template<class T>
int binary_search(const vector<T>& A, T e, int inicio, int final){
    if (inicio <= final){
        int medio = (inicio + final) / 2;
        if (A[medio] == e)
            return medio;
        else if (A[medio] > e)
            return binary_search(A, e, inicio, medio - 1);
        else if (A[medio] < e)
            return binary_search(A, e, medio + 1, final);
    }
    return -1;
}

template<class T>
int linear_search(const vector<T>& A, T e){
    for (int i = 0; i < A.size(); i++){
        if (A[i] == e)
            return i;
    }
    return -1;
}


template<class T>
void is_sorted(vector<T> A){
    for(std::size_t j = 1; j < A.size(); j++){
        assert(A[j-1] <= A[j]);
    }
}

double get_random_number(double& x0){
    x0 = x0 + (double)rand()/RAND_MAX;
    return x0;
}
int main(){
    int N = 100000;
    srand((unsigned)time( NULL ) );
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    vector<double> A(N);
    double seed = 0.0;
    for(double& x: A)
        x = get_random_number(seed);

    is_sorted(A);

    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio

    int indice_a_buscar = N/2;
    int indx1 = binary_search(A, A[indice_a_buscar], 0, N-1);

    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin

    std::chrono::duration<double, std::milli> t1 = fin - inicio;
    cout << "indx1 = " << indx1 << ", ";
    cout << "binary_search (time) = " << t1.count() << "ms" << endl;

    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio

    int indx2 = linear_search(A, A[indice_a_buscar]);

    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin

    std::chrono::duration<double, std::milli> t2 = fin - inicio;
    cout << "indx2 = " << indx2 << ", ";
    cout << "linear_search (time) = " << t2.count() << "ms" << endl;

    return 0;
}