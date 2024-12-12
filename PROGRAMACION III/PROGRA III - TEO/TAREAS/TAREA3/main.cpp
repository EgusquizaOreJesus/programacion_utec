#include <iostream>
#include "vector"
#include "algorithm"
#include "deque"
#include "list"
#include "queue"
#include "array"
#include "forward_list"
#include "stack"
using namespace std;
using I = int;

class A{
    int * tam;
    std::stack<std::pair<I,I> >  Visited_Coordinates;


};
A *initBoard(void){
    A* app = new A;
    return app;
}

template<typename T, template<typename ...>typename Container1 = vector,template<typename ...>typename Container2>
auto split_range(Container2<T> v,int n){
    int range = distance(v.begin(),v.end())/n;
    auto it= v.begin();
    Container1<vector<T>> almacen;
    for (int i = 0; i < n; ++i) {
        vector<T> v2;
        if (i==n-1){
            copy(it, end(v), back_inserter(v2));
        }else{
            copy(it, next(it,range), back_inserter(v2));
        }
        it = next(it,range);
        almacen.push_back(v2);
    }

    return almacen;
}

int main() {
    forward_list<int> v1 = {1, 2, 3, 4, 5, 6, 7,8};
    auto resultado = split_range(v1, 3);
// resultado[0] = {1, 2};
// resultado[1] = {3, 4};
// resultado[2] = {5, 6, 7};
    for (const auto& row : resultado) {
        for (const auto& item : row)
            cout << item << " ";
        cout << endl;
    }
    return 0;
}
