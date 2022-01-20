#include <iostream>
#include <vector>
using namespace std;
// URL : https: // www.udemy.com/course/cpp-data-structures-algorithms-prateek-narang/learn/lecture/27373422?start=225#overview
// Greedy doesn't work
// Use DP

int steps = 0;
int dp[5][5] = {0};
int wines(int arr[], int left, int right, int year)
{
    steps++;
    if (left == right)
    {
        dp[left][right] = arr[left] * year;
        return arr[left] * year;
    }
    // If dp[left][right] is repeating it will repeat in same year so we need not consider year
    if (dp[left][right])
        return dp[left][right];
    // If the state isn't repeated then calculate both the options
    int op1 = arr[left] * year + wines(arr, left + 1, right, year + 1);
    int op2 = arr[right] * year + wines(arr, left, right - 1, year + 1);
    dp[left][right] = max(op1, op2);
    return dp[left][right];
}

int winesBottomUP(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= n; j++)
        {
            int y = n - (j - i);

            if (i == j)
            {
                dp[i][i] = arr[i] * y;
            }
            if (i < j)
            {
                int left = arr[i] * y + dp[i + 1][j];
                int right = arr[j] * y + dp[i][j - 1];
                dp[i][j] = max(left, right);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    return dp[0][n - 1];
}

int main()
{
    int arr[5] = {2, 3, 5, 1, 4};
    int n = 5;
    cout << "Bottom Up Wines" << endl;
    cout << winesBottomUP(arr, n) << endl;
    cout << "Top Down Wines" << endl;
    cout << wines(arr, 0, n - 1, 1) << endl;
    cout << "Number of steps in top down: " << steps << endl;
    // Print DP array
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
}