#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binary(string s, ll N)
{

    if (s.length() == N)
    {
        cout << s << endl;
        return 1;
    }
    if (s.length() > N)
    {
        return 0;
    }
    if (s[s.length() - 1] == '1')
    {
        return binary(s + "0", N);
    }
    return binary(s + "0", N) + binary(s + "1", N);
}

int main()
{
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 1;
        cin >> n;
        vector<string> s;
        cout << binary("", n);
    }
}