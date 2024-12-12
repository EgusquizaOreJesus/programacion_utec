#include <iostream>
#include "vector"
#include "list"
using namespace std;

template <typename T,typename ... Ts>
bool are_same ()
{
    //cout << (std::is_same_v<T, Ts> && ...); // fold expression
    // OTRA FORMA
    if ((std::is_same_v<T, Ts> && ...)){        // lo que hace es que compara el primero tipo con el segundo del paquete
        // y hace lo mismo con los demas, && esto me indica que debe ser todo verdadero para que sea verdadero;
        // osea todos deben ser iguales para que cumpla
        return true;
    }
    return false;
    /*
    OTRA FORMA:
    vector<type_index> vec;
    vec.insert(vec.end(), typeid(T));
    cout << vec.size();
    vec.insert(vec.end(), {typeid(Ts)...});
    cout << vec.size();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[0] != vec[i] ){
            return false;
        }
    }
    return true;
     */

}

int main(){
    cout << boolalpha << are_same<int>() << endl; // true
    cout << boolalpha << are_same<int, int , char>() << endl; // false
    cout << boolalpha << are_same<vector<int>, vector<int> , vector<int>>() << endl; // true
    cout << boolalpha << are_same<int, const int, int&, int &&>() << endl; // false
    return 0;
}