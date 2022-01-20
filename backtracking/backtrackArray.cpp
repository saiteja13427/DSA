#include <bits/stdc++.h>
using namespace std;
#define ll long long

void barray(int arr[], int i, int N)
{

    if (i == N)
    {
        return;
    }
    arr[i] = i + 1;
    barray(arr, i + 1, N);
    //backtracking step
    arr[i] = -arr[i];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int a[n];
        barray(a, 0, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    }
}