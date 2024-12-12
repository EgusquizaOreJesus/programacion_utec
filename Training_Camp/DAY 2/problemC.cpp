#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// usando lower_bound (binary search)
int solve(int x)
{
    ll a = 0;
    ll b = 10e9;
    while (a <= b)
    {
        ll m = a + (b - a) / 2;
        ll sum = (m * (m + 1) / 2);
        if (sum <= x)
        {
            a = m + 1;
        }
        else
        {
            b = m - 1;
        }
    }
    return b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // for taking input
    freopen("output.txt", "w", stdout); // for displaying output
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}