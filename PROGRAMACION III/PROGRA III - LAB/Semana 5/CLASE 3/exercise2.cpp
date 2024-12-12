#include "iostream"
#include "algorithm"
#include "vector"
#include "list"
#include "random"
#include "chrono"
#include "iomanip"
#include "thread"
using type = double;

using namespace std;

template<typename T, template<class ...>typename Container>
void producto_PARTES(Container<T> v1, Container<T> v2,T& result,  int parte, int range){
    int start = (parte) * (v1.size()/range);
    int fin = (parte + 1) * (v1.size()/range);
    for (int i = start; i < fin; ++i) {
        result += *(next(v1.begin(),i)) * *(next(v2.begin(),i));
    }
}

template<typename T, template<class ...>typename Container>
void PRODUCTO_ESCALAR(Container<T> v1, Container<T> v2, T& result){
    result = 0;
    for (int i = 0; i < v1.size(); ++i) {
        result  += (*(next(v1.begin(),i)) * *(next(v2.begin(),i)));
    }
}

void ejercicio_sinHilos(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    t_inicio = chrono::high_resolution_clock::now();
    vector<double> A(100000000);
    vector<double> B(100000000);
    generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    generate(B.begin(), B.end(), [](){return (double)rand()/RAND_MAX;});


    type result = 0;
    PRODUCTO_ESCALAR(A,B,result);

    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    cout << result << endl;

}

void ejercicio_conHilos(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<double> A(100000000);
    vector<double> B(100000000);

    vector<thread> vthreads;
    int n_threads = thread::hardware_concurrency()/2;

    generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    generate(B.begin(), B.end(), [](){return (double)rand()/RAND_MAX;});

    t_inicio = chrono::high_resolution_clock::now();

    vector<double> outs(n_threads,0.);

    for (int i=0; i < n_threads; i++){
        vthreads.push_back(thread(&producto_PARTES<type,vector>, A, B, ref(outs[i]),i,n_threads));
    }


    for (int i=0; i < n_threads; i++){
        vthreads[i].join();
    }

    double res=0.;
    for (int i=0; i < n_threads; i++){
        res += outs[i];
    }
    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    cout << res << endl;
}
int main(){
    ejercicio_conHilos();
    ejercicio_sinHilos();

    return 0;
}