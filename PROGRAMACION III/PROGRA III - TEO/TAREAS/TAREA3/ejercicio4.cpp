#include "set"
#include "vector"
#include "list"
#include "forward_list"
#include "deque"
#include "algorithm"
#include "iostream"
using namespace std;
template<typename T,typename Container>
bool Encontrado(T x,Container y){
    if (find(y.begin(),y.end(),x) != y.end()){
        return false;
    }
    return true;
}

template<typename T, template<typename ...>typename Container = vector>
auto delete_duplicated(Container<T>& v1){
    Container<T> v_result;
    copy_if(v1.begin(),v1.end(), back_inserter(v_result),[&v_result](int x){
        return Encontrado(x,v_result);
    });

    return v_result;
}

int main(){

    list<int> v3 = {1, 1, 1, 1, 3, 2, 2, 2, 2, 5};
    auto v4 = delete_duplicated(v3);	    // {1, 3, 2, 5}

    for_each(v4.begin(),v4.end(),[](int x){cout << x << " ";});
    return 0;
}