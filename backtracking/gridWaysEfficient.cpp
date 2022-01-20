#include <bits/stdc++.h>
using namespace std;

//Most efficient O(m+n) approach for gridWays problem
// Basically the number of permutations possible
// (n-1) Downs and (m-1) Rights
// Answer = (n-1+m-1)!/(n-1)!(m-1)!
int factorial(int x)
{
    int fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << factorial(n + m - 2) / (factorial(n - 1) * factorial(m - 1)) << endl;
}