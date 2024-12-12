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

/// MI FORMA DE HACERLO
void find_string_container(forward_list<string>& l,const string& s1, const string& s2){
    /// before_begin: me indica la posicion antes de la inicial, sirve para poder llegar a insertar la posicion final
    /// en casos de forward list
    auto ite = l.before_begin();
    auto it = l.begin();
    for (it = l.begin(); it != l.end(); it++) {
        if (*it == s1){l.insert_after(it,s2);
            break;}
        ite++;
    }
    if (it == l.end()){
        l.insert_after(ite,s2);
   }
}

/// OTRA MANERA DE HACERLO ES HACIENDO USO DE LA FUNCION "find"
/// find: me permite buscar la posicion de la variable que ponga, si es que no se encuentra me retornara la posicion final
/// osea lista.end()
void foo(forward_list<string>& lista, const string& s1, const string& s2){
    auto it = find(lista.begin(), lista.end(), s1);

    if (it != lista.end()){
        lista.insert_after(it, s2);
    }
    else{
        auto it_prev = lista.before_begin();
        for (string e: lista)
            it_prev++;
        lista.insert_after(it_prev, s2);
    }
}

int main(){
    forward_list<string> lista = {"Hola", "Mundo","en", "C++"};

    string s1 = "en";
    string s2 = "Python y";

    find_string_container(lista, s1, s2);
    for_each(lista.begin(),lista.end(),printContainer<string>());
    cout << endl;

    find_string_container(lista, "in", "...");
    for_each(lista.begin(),lista.end(),printContainer<string>());
    cout << endl;
    return 0;

}