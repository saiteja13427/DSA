#include <bits/stdc++.h>
using namespace std;

//Most complex solition 2^(m+n)
//Better: DP n^2
//Best: Permutations and combinations: Ways = (m-1+n-1)!/(m-1)!(n-1)!  ComplexityO(m+n)
int gridWays(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i == n || j == m)
    {
        return 0;
    }

    int ways = gridWays(i, j + 1, n, m) + gridWays(i + 1, j, n, m);
    return ways;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << gridWays(0, 0, n, m) << endl;
}