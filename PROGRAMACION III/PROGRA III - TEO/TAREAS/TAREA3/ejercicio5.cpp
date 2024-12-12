#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template<typename ...Ts>
auto unpack(Ts& ...ts){
    return tuple<Ts&...>(ts...);
}

int main()
{
    std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
    int key;
    string first_name;
    string last_name;
    double height;
    unpack(key, first_name, last_name, height) = tup1;
    std::cout << key <<  " "<< first_name << last_name << height << endl;
}