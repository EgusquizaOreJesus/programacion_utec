#include "vector"
#include "iostream"
#include "list"
using namespace std;


template<typename C=int>
int pull(const C &x) {
    return x;
}


template<typename T, template<typename ...>typename ...Container1,template<typename ...>typename Container2>
auto zip(Container2<T> v, Container1<T> ... args) {
    vector<Container2<T>> result_final;
    auto it = v.begin();
    for (int i = 0; i < v.size(); ++i) {
        Container2<T> result;
        result.push_back(*it);
        (result.push_back(*next(args.begin(),i)),...);
        it++;
        result_final.push_back(result);
    }
    return result_final;
}


int main(){
    vector<int> v1 = { 11, 12, 13, 14, 15 };
    vector<int> v2 = { 21, 22, 23, 24, 25 };
    vector<int> v3 = { 31, 32, 33, 34, 35 };
    vector<int> v4 = { 41, 42, 43, 44, 45 };
    auto r2 = zip(v1, v2, v3, v4);
    for (const auto& row : r2) {
        for (const auto& value : row)
            cout << value << " ";
    }
// lo impreso sería:
//	    11 21 31 41 12 22 32 42 13 23 33 43 14 24 34 44 15 25 35 45
//	12 22 32
//	13 23 33
    return 0;
}