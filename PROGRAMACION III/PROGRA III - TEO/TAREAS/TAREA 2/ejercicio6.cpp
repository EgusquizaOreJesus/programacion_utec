#include <iostream>
#include <typeindex>
#include "vector"
#include "list"
using namespace std;

template <typename ... Ts,typename T>
int index_of (T a)

{
    vector<type_index> vec;
    vec.insert(vec.end(), {typeid(Ts)...});
    //cout << vec.size();
    int pos = 0;
    for(auto i:vec){
        if (i == typeid(T)){
            return pos;
        }
        ++pos;
    }
    return -1;
    /*
    OTRA FORMA:
     if ((std::is_same_v<Ts, T> || ...)){
        cout << "se encontro" << endl;
    }
     */

}

//COMPLETO
int main()
{
    vector<double> var4;
    std::cout << index_of<int, char, vector<int>, list<double>>(var4) << endl; // El resultado seria: -1
    return 0;
}