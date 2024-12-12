#include "iostream"
#include "vector"
#include "list"
#include "array"
#include "algorithm"
#include "forward_list"


using namespace std;

template<typename Container>
int BUSQUEDALINEAL(Container c, int e){
    for (auto it = c.begin(); it!= c.end(); it++){          // O(n)
        if (*it == e){
            return *it;
        }
    }
    return -1;
}
// Complejidad algoritmica: O(n)


/// PODRIAMOS MEJORAR ESTE ALGORITMO?
// Haciendo una busqueda binaria
template<typename Container,typename Iterator>
int BUSQUEDABINARIA(Container L, Iterator inicio, Iterator final, int find){
    int n = distance(inicio, final);                    // O(1)
    auto middle = next(inicio,n/2);                        // O(1)
    auto prev_middle = next(inicio,(n/2)-1);               // O(1)
    auto next_middle = next(inicio,(n/2)+1);               // O(1)
    if (inicio != final){
        if (*middle == find){                                    // O(1)
            return *middle;                                      // O(1)
        }
        else if(*middle > find){
            return BUSQUEDABINARIA (L, inicio, prev_middle, find);      // f(n/2)
        }
        else if(*middle < find){
            return BUSQUEDABINARIA (L, next_middle, final, find);       // f(n/2)
        }
    }
    return -1;
}
// Complejidad algoritmica: O(log(n))

/// LA SEGUNDA BUSQUEDA ES MAS EFICIENTE

int main(){
    vector<int> v2 = {10,20,30,40,50,60,70,90,100,120};
    list<int> v3 = {10,20,30,40,50,60,70,90,100,120};
    array<int,10> v = {10,20,30,40,50,60,70,90,100,120};
    forward_list<int> v4 = {10,20,30,40,50,60,70,90,100,120};



    cout << BUSQUEDALINEAL(v,10);

    cout << BUSQUEDABINARIA(v,v.begin(),v.end(),10);



    return 0;
}