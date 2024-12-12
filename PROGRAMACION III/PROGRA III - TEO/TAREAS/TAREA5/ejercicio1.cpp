
#include "thread"
#include "mutex"
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
mutex bloque;

template <typename T, template <typename...> class Container>
T sumar(Container<T>& cnt){
    T result = 0;
    int n_hilos = 8;
    vector<thread> vh(n_hilos);
    int n_valores = cnt.size();
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    auto it = cnt.begin();

    for (int i = 0; i < n_hilos; ++i) {
        if (distance(it,end(cnt)) < rango){
            rango = distance(it, end(cnt));}
        vh[i] = thread([&result,cnt,it,rango](){
            T temp = 0;
            auto start = it;
            while (start!= next(it,rango)){
                temp += *start++;      // esto va copiar el valor al total, y va incrementar el start
            }
            bloque.lock();
            result += temp;
            bloque.unlock();
        });
        it = next(it,rango);
    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
    return result;
}

int main(){
    vector<int> v(100000,1);
    for (int i = 0; i < 10000; ++i) {
        int result = sumar(v);
        if (result != 100000){
            cout << "FALLO" << endl;
        }
    }


    return 0;
}