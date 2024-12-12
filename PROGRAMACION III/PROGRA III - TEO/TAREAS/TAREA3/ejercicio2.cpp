#include "algorithm"
#include "vector"
#include "iostream"
#include "cmath"
#include "list"
#include "deque"
#include "forward_list"
using namespace std;
template<typename T, template<typename ...>typename Container1 = vector>
auto sum_range(Container1<T>& v1,Container1<T>& v2){
    vector<T> v1_temp;
    vector<T> v2_temp;
    vector<T> v_result;
    int size1 = distance(v1.begin(),v1.end());
    int size2 = distance(v2.begin(),v2.end());
    if (size1> size2){
        copy(v1.begin(),v1.end(), back_inserter(v1_temp));
        copy(v2.begin(),v2.end(), back_inserter(v2_temp));
    }
    else{
        copy(v2.begin(),v2.end(), back_inserter(v1_temp));
        copy(v1.begin(),v1.end(), back_inserter(v2_temp));
    }
    int range = v2_temp.size();
    auto it = v1_temp.begin();
    int n_splits = ceil(v1_temp.size()/static_cast<float >(range));
    for (int i = 0; i < n_splits; ++i) {
        if (distance(it, end(v1_temp))<range){range = distance(it, end(v1_temp));}
        vector<T> temp;
        copy(it, next(it,range), back_inserter(temp));
        transform(temp.begin(), temp.end(), v2_temp.begin(), back_inserter(v_result), std::plus<>());
        it = next(it,range);
    }
    return v_result;
}
int main(){
    forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
    forward_list<int> fl2 = { 4, 8, 7};

    auto res2 = sum_range(fl1, fl2);
    for (const auto& item : res2)
        cout << item << " ";


    return 0;
}