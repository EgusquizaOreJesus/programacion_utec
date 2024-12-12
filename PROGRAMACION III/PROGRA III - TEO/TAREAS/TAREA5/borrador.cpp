#include "iostream"
#include "vector"
#include "thread"
#include "list"
#include "forward_list"
#include "cmath"
#include "mutex"


using namespace std;
mutex mtx1;
bool esPrimo(int x){
    for (int i = 2; i < x; ++i) {
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

template <typename T, template<typename ...> class Container>
void get_primes(Container<T>& cnt, T start, T stop){
    int n_valores = stop - start +1;
    int n_hilos = 8;
    T rango = ceil(n_valores / static_cast<double>(n_hilos));
    T start_temp = start;
    T stop_temp = start_temp + rango;
    vector<thread> vh(n_hilos);
    vector<vector<T>> resultados;
    vector<T> primos;

    for (int i = 0; i < n_hilos; ++i) {
        vh[i] = thread([&](){
            if (stop_temp > stop){
                stop_temp = stop;}
            T a = start_temp;
            T b = stop_temp;
            while(a!= b){
                if (esPrimo(a)){
                    primos.push_back(a);
                }
                a+=1;
            }
            mtx1.lock();
            start_temp = stop_temp;
            mtx1.unlock();
            mtx1.lock();
            stop_temp += rango;
            mtx1.unlock();

        });

    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
    copy(primos.begin(),primos.end(), back_inserter(cnt));
}

int main(){
    list<int> primos;
    vector<int> primos2;

    for (int i = 1; i < 100; ++i) {
        if (esPrimo(i)){
            primos2.push_back(i);
        }
    }
    get_primes(primos,1,1000);
    cout << endl;
    for_each(primos.begin(),primos.end(),[](int x){cout << x << " ";});
    cout << endl;
    for_each(primos2.begin(),primos2.end(),[](int x){cout << x << " ";});
    cout << endl;

    return 0;
}