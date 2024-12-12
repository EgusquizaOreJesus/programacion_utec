#include <iostream>
#include <vector>

using namespace std;
int lower_bound(vector<int> arr, int x)
{
    int l = 0;
    int r = arr.size() - 1;
    int result = -1;
    while (l <= r)
    {

        int m = l + (r - l) / 2;
        if (arr[m] >= x)
        {
            result = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (arr[result] == x)
    {
        return result;
    }
    return -1;
}

void solve(int t, int x)
{
    vector<int> arr;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < x; i++)
    {
        int b;
        cin >> b;
        cout << lower_bound(arr, b) << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin); // for taking input

    freopen("output.txt", "w", stdout); // for displaying output

#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x;
    cin >> t >> x;
    solve(t, x);
}