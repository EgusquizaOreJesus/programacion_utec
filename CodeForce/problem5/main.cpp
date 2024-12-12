#include <iostream>
#include <vector>
#include "numeric"
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
            sum += x;
        }
        int ans = 0;
        if (sum < s) {
            ans = -1;
        }
        else {
            while (sum != s) {
                int l = 0, r = a.size() - 1, temp1 = 0, temp2 = 0;
                while (a[l] == 0) {
                    l++;
                    temp1++;
                }
                while (a[r] == 0) {
                    r--;
                    temp2++;
                }
                if (temp1 > temp2) {
                    sum -= accumulate(a.end() - temp2 - 1, a.end(), 0);
                    a.resize(n - temp2 - 1);
                    ans += temp2 + 1;
                }
                else if (temp1 < temp2) {
                    sum -= accumulate(a.begin(), a.begin() + temp1 + 1, 0);
                    a.erase(a.begin(), a.begin() + temp1 + 1);
                    ans += temp1 + 1;
                }
                else {
                    sum -= (a.front() + a.back());
                    a.erase(a.begin());
                    a.pop_back();
                    ans += 2;
                }
                n = a.size(); // Agregar esta línea de nuevo para que el algoritmo funcione correctamente en todos los casos.
            }
        }
        cout << ans << endl;
    }
    return 0;
}
