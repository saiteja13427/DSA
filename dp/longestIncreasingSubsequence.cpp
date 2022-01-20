#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Input: 50 4 10 8 30 100
// Output: 4 8 30 100

int LCS(vector<int> &arr)
{
    int len = arr.size();
    vector<int> dp(len);
    dp[0] = 1;
    for (int i = 1; i < len; i++)
    {
        dp[i] = 1;
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] > m)
                    m = dp[j];
            }
        }
        dp[i] += m;
    }
    return *max_element(begin(dp), end(dp));
}

int main()
{
    vector<int> arr = {50, 4, 10, 8, 30, 100};
    cout << LCS(arr);
}