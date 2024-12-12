#include "vector"
#include "iomanip"
#include "iostream"
using namespace std;

int main(){
    string A = "ABCDEF";
    vector<char> B = {'A','B'};
    auto pos = find(A.begin(),A.end(),'D');
    cout << distance(A.begin(),pos);

    return 0;
}