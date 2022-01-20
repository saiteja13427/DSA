#include <bits/stdc++.h>
using namespace std;

// Top Down DP with memoization
vector<int> fib(10000, -1);
int fibTopDownDP(int n)
{
    if (n == 1)
    {
        fib[1] = 0;
        return 0;
    }

    if (n == 2)
    {
        fib[2] = 1;
        return 1;
    }

    int n1, n2;
    if (fib[n - 1] != -1)
    {
        n1 = fib[n - 1];
    }
    else
    {
        n1 = fibTopDownDP(n - 1);
    }

    if (fib[n - 2] != -1)
    {
        n2 = fib[n - 2];
    }
    else
    {
        n2 = fibTopDownDP(n - 2);
    }
    fib[n] = n1 + n2;
    return n1 + n2;
}

// Bottom Up DP iterative
int fibBottomUpDP(int n)
{

    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int a = 0, b = 1, c;

    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    cout << fibTopDownDP(5) << endl;
    cout << fibBottomUpDP(5) << endl;
}