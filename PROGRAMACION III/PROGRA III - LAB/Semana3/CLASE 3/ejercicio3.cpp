#include "iostream"
#include "vector"
#include "set"
#include "algorithm"
#include "iomanip"
#include "forward_list"

using namespace std;

template<class T>
class printContainer{
private:
    char _end;
public:
    printContainer(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << setw(3) << x << _end;
    }
};

dsa

void mi_forma();
void otra_forma();
int main(){
    srand(time(nullptr));
    mi_forma();
    cout << endl;
    otra_forma();

    return 0;
}

void mi_forma(){
    vector<int> v(100);
    set<int> primos;
    /// GENERANDO GRACIAS A LA FUNCION generate, UN VECTOR CON 100 NUMEROS ALEATORIOS ENTRE 0 y 99
    generate(v.begin(),v.end(),[](){return rand()%100;});
    /// IMPRIMOS EL VECTOR CON FOR_eACH
    cout << "Numeros:" << endl;
    for_each(v.begin(),v.end(),[](int x){cout << setw(3) <<x << " ";});
    cout << endl;
    for(auto i: v){
        if (!esCompuesto(i)){
            primos.insert(i);
        }
    }
    /// IMPRIMIENDO DE OTRA MANERA CON EL TEMPLATE DE CLASE :
    cout << "PRIMOS:" << endl;
    for_each(primos.begin(),primos.end(),printContainer<int>());
    cout << endl;
    /// OBS: tambien podria ser asi:
    //for_each(primos.begin(),primos.end(),[](int x){cout << setw(3) <<x << " ";});
    //cout << endl;
}
void otra_forma(){
    forward_list<int> lista(100);
    generate(lista.begin(),lista.end(),[](){return rand()%100;});

    /// TAMBIEN PODRIA SER, PARA AÑADIR ELEMENTOS ASI:
    // forward_list<int> lista;
    // for (int i = 0; i < 100; i++){
    //        lista.push_front(rand()%100);
    //    }
    cout << "numeros:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;

    /// EN ESTE TIPO DE CONTAINER HAY UNA FORMA DE REMOVER MAS FACIL
    /// USANDO LA FUNCION "remove_if"
    lista.remove_if(esCompuesto);
    cout << "\nprimos repetidos:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;


    cout << "\nprimos:" << endl;
    set<int> s(lista.begin(), lista.end());
    for_each(s.begin(),s.end(),printContainer<int>());
    cout << endl;
}