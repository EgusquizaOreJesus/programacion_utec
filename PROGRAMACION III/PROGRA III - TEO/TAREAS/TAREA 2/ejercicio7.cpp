#include "vector"
#include "list"
#include "map"
#include "array"
#include "iostream"

using namespace std;

template<typename T,size_t k>
ostream& operator<<(ostream& os, const array<T,k>& ar){
    os << "{";
    for (int i = 0; i <ar.size()-1; ++i) {
        os << ar[i] << ", ";
    }
    os << ar[ar.size()-1] << "}";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& ar){
    os << "{";
    for (int i = 0; i <ar.size(); ++i) {
        os << ar[i] << ", ";
    }
    os << "}";
    return os;
}

template<typename T=int>
ostream& operator<<(ostream& os, const list<T>& ar){
    os << "{";
    for (auto i:ar) {
        os << i << ",";
    }
    os << "}";
    return os;
}

template<typename T,typename K>
ostream& operator<<(ostream& os, const map<T,K>& ar){
    os << "{";
    for (auto i:ar) {
        os << "{"<<i.first << ":" << i.second << "}" << ",";
    }
    os << "}";
    return os;
}
//COMPLETO
int main(){
    std::map<char, int> mp = {{'a', 10}, {'b', 20}, {'c', 30}};
    std::cout << "Los valores de mp son: " << mp << std::endl; // Los valores de mp son: {{a: 10}, {b: 20}, {c: 30}}

    return 0;
}
