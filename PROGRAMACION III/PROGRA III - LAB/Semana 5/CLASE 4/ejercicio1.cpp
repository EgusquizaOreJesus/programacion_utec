#include "thread"
#include "mutex"
#include "iostream"
#include "vector"
#include "chrono"
#include "cmath"
using namespace std;
using namespace std::chrono;
mutex bloqueo;

void sum_elem_con_hilos_partes(vector<int>::iterator start, vector<int>::iterator finish,int& result){
    int temp = 0;
    for(auto i=start; i!=finish; i++){
        temp += (*i);
    }
    bloqueo.lock();
    result += temp;
    bloqueo.unlock();
}

int sum_elem_con_hilos(){
    int n_hilos=2;
    int n_valores = 10000000;
    vector<int> v(n_valores,1);
    vector<thread> vh(n_hilos);
    int range= ceil(n_valores/static_cast<double>(n_hilos));
    auto it = v.begin();
    int result = 0;
    for (int i = 0; i < n_hilos; ++i) {
        if (distance(it,end(v)) < range){range = distance(it, end(v));}
        vh[i] = thread(sum_elem_con_hilos_partes,it, next(it,range),ref(result));
        it = next(it,range);
    }
    for(auto& h:vh){
        h.join();
    }
    return result;
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    t_inicio = chrono::high_resolution_clock::now();
    cout << sum_elem_con_hilos() << endl;
    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    return 0;
}