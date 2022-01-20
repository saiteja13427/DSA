#include <iostream>
#include <vector>
using namespace std;

// Input: Prices, weights and capacity
// Output: Max Price/Profit

// Recursive
int maxProfit(vector<int> &wts, vector<int> &price, int capacity, int i)
{
    if (i < 0 || capacity < 0)
        return 0;

    int include = 0;
    if (capacity - wts[i] > 0)
        include = price[i] + maxProfit(wts, price, capacity - wts[i], i - 1);
    int exclude = maxProfit(wts, price, capacity, i - 1);

    return max(include, exclude);
}

// Iterative
int maxProfitBottomUp(vector<int> &wts, vector<int> &price, int capacity)
{
    int len = wts.size();
    int arr[len + 1][capacity + 1];
    for (int i = 0; i <= capacity; i++)
    {
        arr[0][i] = 0;
    }
    for (int i = 0; i <= len; i++)
    {
        arr[i][0] = 0;
    }

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            int include = 0, exclude = 0;
            if (wts[i - 1] <= j)
                include = price[i - 1] + arr[i - 1][j - wts[i - 1]];
            exclude = arr[i - 1][j];
            arr[i][j] = max(include, exclude);
        }
    }
    return arr[len][capacity];
}

// Iterative Optimised
int maxProfitBottomUpOpt(vector<int> &wts, vector<int> &price, int capacity)
{
    int len = wts.size();
    // Just using 2 rows instead of lemm rows
    int arr[2][capacity + 1];

    for (int j = 0; j <= capacity; j++)
    {
        arr[0][j] = 0;
        arr[1][j] = 0;
    };

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            int include = 0, exclude = 0;
            if (wts[i - 1] <= j)
                include = price[i - 1] + arr[0][j - wts[i - 1]];
            exclude = arr[0][j];
            arr[1][j] = max(include, exclude);
        }
        for (int j = 0; j <= capacity; j++)
        {
            arr[0][j] = arr[1][j];
        };
    }
    return arr[1][capacity];
}

int main()
{
    int capacity = 11;
    vector<int> price = {5, 20, 20, 10};
    vector<int> wts = {2, 7, 3, 4};
    cout << "Recursive: ";
    cout << maxProfit(wts, price, capacity, 4) << endl;
    cout << "Iterative O(NW) Space: ";
    cout << maxProfitBottomUp(wts, price, capacity) << endl;
    cout << "Iterative O(W) Space: ";
    cout << maxProfitBottomUpOpt(wts, price, capacity);
}