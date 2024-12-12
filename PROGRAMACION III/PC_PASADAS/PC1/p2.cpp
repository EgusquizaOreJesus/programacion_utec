#include "iostream"

using namespace std;

template<typename ...Ts>
auto print(Ts ... ts){
    if constexpr (sizeof ...(ts)==0){cout << endl;}
    ((cout << ts << " "), ...);
}



int main(){
    print (1);
    print();
    print(1,'a',4.5,"Hola Mundo", false);
}