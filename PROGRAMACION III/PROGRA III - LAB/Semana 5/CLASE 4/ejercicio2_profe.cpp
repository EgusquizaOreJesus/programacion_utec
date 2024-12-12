#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <mutex>
#include <assert.h>

using namespace std;

mutex mtx;

void dot(vector<int> A, vector<int> B, int& s, int chunk, int chunks){
    int inicio = chunk * (A.size()/chunks);
    int fin = (chunk + 1) * (A.size()/chunks);
    int s_ = 0;

    for (int i=inicio; i < fin; i++)
        s_ += A[i] * B[i];

    mtx.lock();
    s = s + s_;
    mtx.unlock();

}

void dot_(vector<int> A, vector<int> B, int& s){
    for (int i=0; i < A.size(); i++)
        s += A[i] * B[i];
}
void ejercicio(){
    int N = 100000000;

    vector<int> A(N, 1.);
    vector<int> B(N, 1.);

    vector<thread> vthreads;
    int n_threads = 4;


    int res=0.;
    for (int i=0; i < n_threads; i++)
        vthreads.push_back(thread(&dot,A,B,ref(res),i,n_threads));

    for (int i=0; i < n_threads; i++)
        vthreads[i].join();
    //dot_(A,B,res);
    cout << "<A . B> = " << res << endl;
    assert(res == N);
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    t_inicio = chrono::high_resolution_clock::now();

    ejercicio();
    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    return 0;
}
