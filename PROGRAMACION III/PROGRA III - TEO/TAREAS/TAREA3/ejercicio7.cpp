#include "algorithm"
#include "vector"
#include "iostream"
#include "list"

using namespace std;
template<typename T, template<typename ...>typename Container = vector>
Container<T> rotate_range(Container<T> v, int x){
    Container<T> result;
    auto it = v.begin();
    if (x>0){
        it = prev(end(v),x);
    }
    if (x<0){
        it = prev(begin(v),x);
    }
    copy(it,v.end(), back_inserter(result));
    copy(v.begin(),it, back_inserter(result));
    return result;
}



int main(){
    list<int> v1 = {10, 20, 30, 40, 50};
    auto v3 = rotate_range(v1, -2);	 	// {30, 40, 50, 10, 20}

    for_each(v3.begin(),v3.end(),[](int x){cout << x << " ";});
    return 0;
}