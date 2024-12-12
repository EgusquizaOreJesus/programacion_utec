#include "iostream"
#include "vector"


using namespace std;

template<typename T=int,typename ...Ts>
class MiLista{
    vector<T> a;
public:
    friend ostream& operator<<(ostream& os, const MiLista& l) {
        os << "[ ";
        for (int i = 0; i <l.a.size() ; ++i) {
            os << l.a[i] << " ";
        }
        os << "]";
        return os;
    }
    MiLista& operator<<(const T& value){
        this->a.push_back(value);
        return *this;
    };
    template<typename ... argumentos>
    explicit MiLista(argumentos... valores){
        (a.push_back(valores),...);
    }

    MiLista operator+(const MiLista& other){
        MiLista temp;
        for (int i = 0; i < a.size(); ++i) {
            temp.a.push_back(a[i]);
        }
        for (int i = 0; i < other.a.size(); ++i) {
            temp.a.push_back(other.a[i]);
        }
        return temp;
    }

};
int main () {
    MiLista < > lista1 ;
    MiLista < int > lista2 (1,2.3) ;
    MiLista < float > lista3 (2.1 ,3.2 ,0.4,2) ;
    cout << lista1 << endl ;
    cout << lista2 << endl ;
    cout << lista3 << endl ;
    lista1 <<2 <<5;
    lista2 <<9;
    cout << lista1 << endl ;
    cout << lista2 << endl ;
    MiLista < int > lista4 = lista1 + lista2 ;
    cout << lista4 << endl ;
}