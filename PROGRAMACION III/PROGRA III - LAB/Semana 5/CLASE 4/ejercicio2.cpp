#include "thread"
#include "mutex"
#include "iostream"
#include "vector"
#include "chrono"
#include "cmath"

using namespace std;
using namespace std::chrono;
mutex block;

void product_escalar(vector<int> v1, vector<int> v2, int start, int final,int& result){
    int temp = 0;
    for (int i = start; i < final; ++i) {
        temp += v1[i] * v2[i];
    }
    block.lock();
    result += temp;
    block.unlock();
}
int prod_escalar_sin_Hilos(){
    int n_valores = 10000000;
    vector<int> v1(n_valores,1);
    vector<int> v2(n_valores,1);
    int result = 0;
    for (int i = 0; i < n_valores; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

int prod_escalar_conHilos(){
    int n_valores = 100000000;
    int n_hilos = 4;
    vector<int> v1(n_valores,1);
    vector<int> v2(n_valores,1);
    int rango = ceil(n_valores/static_cast<double>(n_hilos));
    int start_temp = 0;
    int stop_temp = start_temp + rango;
//    vector<thread> vh(n_hilos);
    vector<thread> vh;
    int result = 0;
    for (int i = 0; i < n_hilos; ++i) {
        if (stop_temp>n_valores){
            stop_temp = n_valores;
        }
        vh.push_back(thread(product_escalar,v1,v2,start_temp,stop_temp, ref(result)));
//        vh[i] = thread(product_escalar,v1,v2,start_temp,stop_temp, ref(result));
        start_temp = stop_temp;
        stop_temp += rango;
    }
    for(auto& h:vh){
        h.join();
    }
    return result;
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    t_inicio = chrono::high_resolution_clock::now();
    //cout << prod_escalar_sin_Hilos() << endl;     media: 200ms
    cout << prod_escalar_conHilos() << endl;

    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;


    return 0;
}
