#include <iostream>
#include "thread"
#include "chrono"
#include "vector"
#include "mutex"
#include "cmath"
using namespace std;
mutex bloqueo;

template<typename Iterator, typename T = typename Iterator::value_type>
void sumar_ref(Iterator start, Iterator stop, T& result){
    T temp = 0;
    while (start!= stop){
        temp += *start++;      // esto va copiar el valor al total, y va incrementar el start
    }
    bloqueo.lock();
    result += temp;
    bloqueo.unlock();

}

void suma(){

}
int suamr(vector<int>& v){
    int n_hilos = 100;
    int n_valores = v.size();
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    vector<thread> v_hilos(n_hilos);           // Hilos
    auto it = v.begin();
    int result = 0;
    for (int i = 0; i < n_hilos; ++i) {
        if (distance(it,end(v)) < rango){rango = distance(it, end(v));}
        v_hilos[i] = thread(sumar_ref<vector<int>::iterator>,it, next(it,rango), ref(result));
        it = next(it,rango);

    }
    for (int i = 0; i < n_hilos; ++i) {
        v_hilos[i].join();
    }
    return result;
}

int main() {
    vector<int> v(100000,1);
    for (int i = 0; i < 1000; ++i) {
        if (suamr(v) != 100000){
            cout << "FALLO";
        }
    }


    return 0;
}
