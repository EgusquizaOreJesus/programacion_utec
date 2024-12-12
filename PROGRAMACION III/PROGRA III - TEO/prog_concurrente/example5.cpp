#include "thread"
#include "vector"
#include "random"
#include "iostream"

using namespace std;

/// COMO HACER SI YO QUIERO EJECUTAR UN CONJUNTO DE  HILOS PARA PROCESAR INFORMACION DE FORMA PARALELA


/// vamos a crar un vector con multiples hilos para que puedan trabajar de forma paralela una parte de la informacion

template<typename T, int sz>
vector<T> generar_vector_aleatorio(int first, int last){
    vector<T> v(sz);
    random_device rd;
    if (typeid(T) == typeid(double) || typeid(T) == typeid(float)){
        uniform_real_distribution<double> dis(1,20);
        generate(v.begin(),v.end(),[&dis,&rd](){return dis(rd);});
    }else{
        uniform_int_distribution dis(first, last);
        generate(v.begin(),v.end(),[&dis,&rd](){return dis(rd);});
    }
    return v;
}
/// dato curioso de templates: normalmente se pone el tipo y luego el no tipo
void sumar_rango(int start, int stop,vector<int>& datos, int& result){
    for (int i = start; i < stop; ++i) {
        result += datos[i];
    }
}

void ejemplo_multiples_hilos_vector(){
    /// Generando un vector aleatorio de 100 valores, con numeros aleatorios del 1 al 20:
    auto v1 = generar_vector_aleatorio<int,100>(1,20);
    // creo un vector de hilos de 4
    vector<thread> vh(4);

    const int sz_thread = 4;
    vector<int> resultados(sz_thread);
    auto actual_pos = 0;
    auto range = 25;
    auto i = 0;
    for(auto& hilo:vh){
        hilo = thread(sumar_rango,
                      range*i,
                      range * (i+1),
                      ref(v1),
                      ref(resultados[i])
                      );
        i++;
    }
    // OBS NUNCA OLVIDAR PONER EL JOIN PARA CADA HILO
    /// ESO HACERLO EN UN FOR DIFERENTE
    for(auto& hilo: vh){
        hilo.join();
    }
    /// comparando el total de forma secuencial y el total de forma paralela
    auto total_secuencial = accumulate(v1.begin(),v1.end(),0);
    auto total_paralelo = accumulate(resultados.begin(),resultados.end(),0);
    cout << total_secuencial << "==" << total_paralelo << endl;
}
/// OTRA FORMA DE HACERLO ES CON ITERADORES
/// Dicha forma seria mas generica y se podria usar con diferentes contenedores
template<typename T>
void ejemplo_multiples_hilos_contenedor_iteradores(){
    /// Generando un vector aleatorio de 100 valores, con numeros aleatorios del 1 al 20:
    auto v1 = generar_vector_aleatorio<T,100>(1,20);
    // creo un vector de hilos de 4
    vector<thread> vh(4);

    const int sz_thread = 4;
    vector<T> resultados(sz_thread);
    auto range = 25;
    auto curren_iter = begin(v1);
    auto result_iter = begin(resultados);

    for(auto& hilo:vh){
        auto next_iter = next(curren_iter,range);
        hilo = thread([curren_iter,result_iter,next_iter](){
            *result_iter = accumulate(curren_iter,next_iter,0.0);
        });
        curren_iter = next_iter;
        ++result_iter;
    }
    // OBS NUNCA OLVIDAR PONER EL JOIN PARA CADA HILO
    /// ESO HACERLO EN UN FOR DIFERENTE
    for(auto& hilo: vh){
        hilo.join();
    }
    /// comparando el total de forma secuencial y el total de forma paralela
    auto total_secuencial = accumulate(v1.begin(),v1.end(),0.0);
    auto total_paralelo = accumulate(resultados.begin(),resultados.end(),0.0);
    cout << total_secuencial << "==" << total_paralelo << endl;
}
int main(){
    ejemplo_multiples_hilos_contenedor_iteradores<float>();



    return 0;
}
