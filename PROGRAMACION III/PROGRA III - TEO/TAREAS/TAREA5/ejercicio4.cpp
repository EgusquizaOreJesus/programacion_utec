#include "thread"
#include "vector"
#include "iostream"
#include "forward_list"
using namespace std;

template<typename T>
class linked_list_t{
    forward_list<T> list;
public:
    void push_front(const T& value){
        list.push_front(value);
    }
    void pop_front(){
        list.pop_front();
    }
    bool empty(){
        if (list.empty()){
            return true;
        }
        return false;
    }
    int size(){
        int size = distance(list.begin(),list.end());
        return size;
    }
    auto begin(){
        return list.begin();
    }
    auto end(){
        return list.end();
    }
};


int main(){
    linked_list_t<int> ll;
    // cantidad
    int nhilos = {};
    cin >> nhilos;
    // Hilos
    vector <thread> vhilos(nhilos);
    for (int i = 0; i < nhilos - nhilos/4; ++i)
        vhilos[i] = thread([&ll, i] { ll.push_front(i); });
    for (int i = nhilos - nhilos/4; i < nhilos; ++i)
        vhilos[i] = thread([&ll] { ll.pop_front(); });
    for (auto& hilo: vhilos) hilo.join();
    // Resultado
    cout << ll.size() << endl;
    return 0;
}