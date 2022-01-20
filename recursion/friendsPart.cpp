#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll friends(ll N)
{

    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return 1;
    }
    return friends(N - 1) + (N - 1) * friends(N - 2);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << friends(n);
    }
}