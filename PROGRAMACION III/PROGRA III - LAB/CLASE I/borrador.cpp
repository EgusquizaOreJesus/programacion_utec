#include <bits/stdc++.h>
#include <random>
#include <iomanip>


using namespace std;

int main()
{
    random_device rd;
    uniform_real_distribution<float> dist(0, 1);

    for (int n = 0; n < 5; ++n) {
        cout << setprecision(5)
             << dist(rd) << "\n";
    }
    cout << endl;

    return 0;
}