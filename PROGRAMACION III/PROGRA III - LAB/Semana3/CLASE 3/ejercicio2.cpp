#include <iostream>
#include <map>
#include "vector"
#include "random"
#include "algorithm"
#include "iomanip"

using namespace std;

void moda(vector<int>& v){
    map<int,int> count;
    for(auto i:v){
        count[i]++;
    }
    /// ITERAR SOBRE UN MAP;
    for (const auto &w: count){
        cout << w.first << ": ";        // Imprimimos el key
        cout << w.second;               // Imprimimos el value
        cout << (w.second > 1 ? " veces": " vez") << endl;
    }
    int moda=0;
    int num;
    for (const auto &i: count){
        if (i.second>moda){
            moda = i.second;
            num = i.first;
        }
    }
    cout << "Moda: " << moda;
    cout <<", con " << num << " rep." << endl;
}

template<typename T>
class printContainer{
    char end_;
public:
    explicit printContainer(char end=' '):end_(end){};
    void operator() (T x){
        cout << setw(3) <<x << end_;
    }
};
void mi_forma();
void otra_forma();

int main(){
    mi_forma();
    cout << endl;
    otra_forma();
    return 0;
}

void mi_forma(){
    vector<int> v;
    random_device rd;
    uniform_int_distribution<int> dis(0,20);
    for (int i = 0; i < 100; ++i) {
        v.push_back(dis(rd));
    }
    for_each(v.begin(),v.end(),printContainer<int>(' '));
    cout << endl;
    moda(v);
}
void otra_forma(){
    srand(time(nullptr));
    vector<int> nums(300);
    map<int, int> hist;

    /// PARA RELLENAR UN VECTOR SIN NECESIDAD DE UN BUCLE FOR
    /// Se puede usar la funcion generate(), que recorre cada elemento del vector, adicional con una funcion que retorne un valor
    /// Para asignarle al vector
    generate(nums.begin(), nums.end(), [](){return rand()%16;});

    /// Para visualizar los elementos de un contenedor usar dicha funcion:
    for_each(nums.begin(), nums.end(), [](int x){cout << setw(3)<<x << " ";});
    cout << endl;

    /// Aqui asignamos los valores en el map y sus veces que se repiten dicha misma palabra:
    /// Acuerdate:

    // Si el numero no se encuentra en el contenedor se creara un nuevo elemento con "key"
    // igual a "num" y un "value" igual a 0. Luego este valor se incrementa en 1 en 1 por cada vez que se encuentra la misma palabra

    // Si la palabra ya existe en el contenedor, su valor se incrementa en 1. Esto me indica las veces que se repite la palabra
    for (auto it = nums.begin(); it!=nums.end();  it++){
        hist[*it]++;
    }

    /// ITERAR SOBRE UN MAP;
    for (const auto &w: hist){
        cout << w.first << ": ";        // Imprimimos el key
        cout << w.second;               // Imprimimos el value
        cout << (w.second > 1 ? " veces": " vez") << endl;
    }
    cout << endl;
    auto it = hist.begin();
    pair<int, int> max_pair = {(*it).first, (*it).second};

    for (auto pair: hist){
        if (pair.second > max_pair.second){
            max_pair.second = pair.second;
            max_pair.first = pair.first;
        }
    }

    cout << "Moda: " << max_pair.first;
    cout <<", con " << max_pair.second << " rep." << endl;

}