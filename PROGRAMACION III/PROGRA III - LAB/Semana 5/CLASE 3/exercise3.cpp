#include "iostream"
#include "vector"
#include "thread"
#include "mutex"
#include "cmath"
#include "chrono"
using namespace std::chrono;

using namespace std;
mutex bloqueo;

bool esPrimo(int x){
    for (int i = 2; i < x ; ++i) {
        if (x%i == 0){
            return false;
        }
    }
    return true;
}
int count_primes( int start, int stop){
    int n_valores = stop - start +1;
    int n_hilos = 1000;
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    int start_temp = start;
    int stop_temp = start + rango;
    int primos=0;
    vector<thread> vh(n_hilos);
    for (int i = 0; i < n_hilos; ++i) {
        if (stop_temp>stop){
            stop_temp = stop;
        }
        vh[i] = thread([start_temp,stop_temp,&primos](){
            for (int j = start_temp; j < stop_temp; ++j) {
                if (esPrimo(j)){
                    bloqueo.lock();
                    primos++;
                    bloqueo.unlock();
                }
            }
        });
        start_temp = stop_temp;
        stop_temp = start_temp + rango;
    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
    return primos;
}
int count_primes_sin_Hilos(int start, int stop){
    int primos = 0;
    for (int i = start; i < stop; ++i) {
        if (esPrimo(i)){

            primos++;
        }
    }
    return primos;
}


int main(){
    auto t1 = high_resolution_clock::now();
//    cout << count_primes_sin_Hilos(2, pow(2,20)) << endl;
      cout << count_primes(2, pow(2,25)) << endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    cout<<"La funcion sin hilos toma: "<< ms_double.count()<<"ms"<<endl;





    return 0;
}