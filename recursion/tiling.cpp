#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tile(ll n, ll m)
{
    if (n <= m - 1)
    {
        return 1;
    }
    return tile(n - 1, m) + tile(n - m, m);
}

int main()
{
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, ans = 1;
        cin >> n >> m;
        cout << tile(n, m);
    }
}