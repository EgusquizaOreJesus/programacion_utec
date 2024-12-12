#include "iostream"
#include "thread"
#include "vector"
#include "list"
#include "forward_list"
#include "cmath"
#include "mutex"


using namespace std;
mutex mtx;
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
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    int start_temp = start;
    int stop_temp = start + rango;
    vector<thread> vh(n_hilos);
    vector<T> primos;
    for (int i = 0; i < n_hilos; ++i) {
        if (stop_temp > stop){
            stop_temp = stop;}
        vh[i] = thread([start_temp,stop_temp,&primos](){
            for (int j = start_temp; j < stop_temp; ++j) {
                if (esPrimo(j)){
                    mtx.lock();
                    primos.push_back(j);
                    mtx.unlock();
                }
            }
        });
        start_temp = stop_temp;
        stop_temp += rango;
    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
    sort(primos.begin(),primos.end());
    copy(primos.begin(),primos.end(), back_inserter(cnt));
}

int main(){
    vector<int> primos;
    vector<int> primos2;

    for (int i = 1; i < 100; ++i) {
        if (esPrimo(i)){
            primos2.push_back(i);
        }
    }
    get_primes(primos,10,100);
    for_each(primos.begin(),primos.end(),[](int x){cout << x << " ";});
    cout << endl;
    for_each(primos2.begin(),primos2.end(),[](int x){cout << x << " ";});
    cout << endl;

    return 0;
}
///USANDO SORT
/*

#include "iostream"
#include "thread"
#include "vector"
#include "list"
#include "forward_list"
#include "cmath"
#include "mutex"


using namespace std;
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
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    int start_temp = start;
    int stop_temp = start + rango;
    vector<thread> vh(n_hilos);
    vector<T> primos;
    for (int i = 0; i < n_hilos; ++i) {
        if (stop_temp > stop){
            stop_temp = stop;}
        vh[i] = thread([start_temp,stop_temp,&primos](){
            for (int j = start_temp; j < stop_temp; ++j) {
                if (esPrimo(j)){
                    primos.push_back(j);
                }
            }
        });
        start_temp = stop_temp;
        stop_temp += rango;
    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
    sort(primos.begin(),primos.end());
    copy(primos.begin(),primos.end(), back_inserter(cnt));
}
 */