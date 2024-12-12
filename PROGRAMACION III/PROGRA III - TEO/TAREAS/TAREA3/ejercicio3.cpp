#include "algorithm"
#include "vector"
#include "iostream"
#include "cmath"
#include "list"
#include "deque"
#include "forward_list"
using namespace std;

template<typename T,typename Container>
bool Encontrado(T x,Container y){
    if (find(y.begin(),y.end(),x) != y.end()){
        return false;
    }
    return true;
}

template<typename T, template<typename ...>typename Container = vector>
Container<T> delete_range(Container<T>& v1, vector<T> LIST){
    Container<T> v_result;
    copy_if(v1.begin(), v1.end(), back_inserter(v_result),[&LIST](T x){
        return Encontrado(x,LIST);
    });
    return v_result;
}
template<typename T, template<typename ...>typename Container = vector>
Container<T> delete_range(Container<T>& v1, int values){
    Container<T> v_result;
    copy_if(v1.begin(), v1.end(), back_inserter(v_result),[values](int x){return x!= values;});
    return v_result;
}

int main(){
    list<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
    auto v3 = delete_range(v1, {1, 4});	 // {3, 3, 2, 3, 6, 5}
    for_each(v3.begin(),v3.end(),[](int x) {cout << x << " ";});
    return 0;
}
