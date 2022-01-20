#include <bits/stdc++.h>
using namespace std;

// Bottom Up Iterative DP
int bottomUp(vector<int> &arr, int m)
{
    vector<int> dp(m + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT_MAX;
        for (auto c : arr)
        {
            if (i - c >= 0 and dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[m] == INT_MAX ? -1 : dp[m];
}

// Top Down recursive dp with memoization
vector<int> coin(1000, -1);
int topDown(vector<int> &arr, int len, int m)
{
    if (m == 0)
    {
        coin[0] = 0;
        return 0;
    }

    int mins = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        if (m - arr[i] >= 0)
        {
            if (coin[m - arr[i]] != -1)
            {
                mins = min(mins, coin[m - arr[i]]);
            }
            else
            {
                int x = topDown(arr, len, m - arr[i]);
                mins = min(mins, 1 + x);
                coin[m - arr[i]] = 1 + x;
            }
        }
    }

    return mins == INT_MAX ? -1 : mins;
}

int main()
{
    int n = 4;
    vector<int> arr = {1, 2, 7, 10};
    int m = 3;

    cout << topDown(arr, 4, m) << endl;
    cout << bottomUp(arr, m) << endl;
}