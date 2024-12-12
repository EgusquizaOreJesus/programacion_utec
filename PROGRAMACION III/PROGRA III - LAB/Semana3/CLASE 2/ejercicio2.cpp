#include "forward_list"
#include "iostream"
#include "random"
#include "algorithm"

using namespace std;

template<typename T>
class printContainer{
    char end_;
public:
    explicit printContainer(char end=' '):end_(end){};
    void operator() (T x){
        cout << x << end_;
    }
};

bool esCompuesto(int x){
    for (int i = 2; i < x; ++i) {
        if (x%i ==0){
            return true;
        }
    }
    return false;
}

int main(){
    random_device rd;
    uniform_int_distribution<int> dis(0,99);
    forward_list<int> list;
    for (int i = 0; i < 10; ++i) {
        list.push_front(dis(rd));
    }
    for_each(list.begin(),list.end(),printContainer<int>());
    cout << endl;


    /// usamos el remove_if: para remover los numeros que sean compuestos
    list.remove_if(esCompuesto);
    for_each(list.begin(),list.end(),printContainer<int>());
    cout << endl;

    /// primos generados en total:
    /// para hallarlo usaremos la funcion "distance"
    cout << "primos en total es: " << distance(list.begin(),list.end()) << endl;


    return 0;
}