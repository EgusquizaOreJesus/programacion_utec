#include <iostream>
#include <future>
#include <chrono>
#include <vector>
#include "cmath"
using namespace std;

void suma(promise<int>* obj, int N){
    int s = 0;
    for (int i=1; i<=N; i++)
        s += i;
    obj->set_value(s);
}

void factorial(promise<int>* obj, int N){
    int prod = 1;
    for (int i=1; i<=N; i++)
        prod *= i;
    obj->set_value(prod);
}
void suma_cuadrados(promise<int>* obj, int N) {
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += static_cast<int>(pow(i, 2));
    }
    obj->set_value(sum);
}

int fibonacci(int N){
    int fn;
    if (N <= 2)
        return 1;
    else{
        int f_1 = 1;
        int f_2 = 1;
        fn = f_2;
        for (int i=3; i <= N; i++){
            fn = f_1 + f_2;
            f_1 = f_2;
            f_2 = fn;
        }
    }
    return fn;
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    int N;
    cout << "Ingrese N: ";
    cin >> N;
    cout << endl;

    t_inicio = chrono::high_resolution_clock::now();
    promise<int> promise_obj1;
    promise<int> promise_obj2;
    promise<int> promise_obj3;

    /// asigno los future que van a recibir los valores de promise
    future<int> res1 = promise_obj1.get_future();
    future<int> res2 = promise_obj2.get_future();
    future<int> res3 = promise_obj3.get_future();

    thread t1(suma, &promise_obj1, N);
    thread t2(factorial, &promise_obj2, N);
    thread t3(suma_cuadrados,&promise_obj3,N);
    cout << "Respuesta fibonacci(N) = " << fibonacci(N) << endl;
    cout << "Respuesta factorial(N) = " << res2.get() << endl;
    cout << "Respuesta suma(N) = " << res1.get() << endl;
    cout << "Respuesta suma cuadrados(N) = " << res3.get() << endl;
    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    t1.join();
    t2.join();
    t3.join();
    return 0;
}