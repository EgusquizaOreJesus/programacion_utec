#include <iostream>
using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        array[i] = a;
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i]>=array[k-1] && array[i]>0){
            result++;
        }
    }
    cout << result;
}
