#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// upper_bound el primer elemento que es mayor que x
int upper_bound(vector<int> arr, int x)
{
    int l = 0;
    int r = arr.size() - 1;
    int result = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > x)
        {
            result = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    if (result == -1)
    {
        return arr.size();
    }
    return result;
}

// lower_bound el primer elemento que es mayor o igual que x
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

    if (result == -1)
    {
        return arr.size();
    }
    return result;
}

void solve(int t)
{
    vector<int> arr;
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        arr.push_back(n);
    }
    // ordenar el vector
    sort(arr.begin(), arr.end());

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int result = upper_bound(arr, x);
        cout << result << "\n";
    }
}

// binary search NO RECURSIVE

int main()
{

    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin); // for taking input

    freopen("output.txt", "w", stdout); // for displaying output

    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    solve(t);
    return 0;
}