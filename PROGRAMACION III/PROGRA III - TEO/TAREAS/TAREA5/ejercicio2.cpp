#include "thread"
#include "mutex"
#include "iostream"
#include "vector"
#include "cmath"
using namespace std;
mutex bloque;

template<typename T, template<typename ...> class Container>
void increase_values(Container<T>& cnt, T value){
    T result = 0;
    int n_hilos = 8;
    vector<thread> vh(n_hilos);
    int n_valores = cnt.size();
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    auto it = cnt.begin();
    for (int i = 0; i < n_hilos; ++i) {
        if (distance(it,end(cnt)) < rango){
            rango = distance(it, end(cnt));}
        vh[i] = thread([it,rango,value](){
            for (int j = 0; j < rango; ++j) {
                *(next(it,j)) += value;
            }
        });
        it = next(it,rango);
    }
    for (int i = 0; i < n_hilos; ++i) {
        vh[i].join();
    }
}
/// NO SE NECESITA MUTEX PORQUE EN CADA THREAD NO ESTAMOS ACTULIZANDO UN MISMO VALOR ESTAMOS AGARRANDO BLOQUES DIFERENTES DE VALORES
int main() {
    vector<int> v(100,1);
    auto it = v.begin();
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;
    increase_values(v,2);
    for(auto& n: v){
        if (n!=3){
            cout << "FALLO" << endl;
        }
    }
    for_each(v.begin(),v.end(),[](int x){cout << x << " ";});
    cout << endl;

    return 0;
}