#include <iostream>
using namespace std;

int main() {
    int n;
    string palabra;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> palabra;
        if (palabra.length() > 10){
            cout << *palabra.begin() << palabra.length()-2 << *(palabra.end()-1) << endl;
        }
        else{
            cout << palabra << endl;
        }
    }
    return 0;
}
