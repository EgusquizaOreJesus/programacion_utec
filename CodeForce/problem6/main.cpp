#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--){
        int a;
        cin >> a;
        int result = 0;
        for (int i = 0; i < 3; ++i) {
            int temp;
            cin >> temp;
            if (temp > a){
                result++;
            }
        }
        cout << result << endl;
    }



    return 0;
}
