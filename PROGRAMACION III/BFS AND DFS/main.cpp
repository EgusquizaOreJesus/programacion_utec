#include <iostream>
#include "vector"
#include "stack"


using namespace std;

bool buscar_coordinates(int x, int y, const vector<pair<int,int>>& p){
    for (auto i:p){
        if (i.first == x and i.second == y){
            return true;
        }
    }
    return false;
}

int main() {
    pair<int, int> p1;
    vector<pair<int,int>> v;
    stack<pair<int,int>> c;

    pair<int,int> p6 = {2,3};
    c.push(p6);

    p1.first = 5;
    p1.second = 3;
    v.push_back(p1);
    c.push(p1);

    pair<int,int> p2 = {10,5};
    pair<int,int> p3 = {9,5};
    c.push(p2);
    c.push(p3);
    c.pop();
    cout << c.top().first;

    cout << boolalpha << buscar_coordinates(9,5,v);

    return 0;
}
