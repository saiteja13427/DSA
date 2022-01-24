#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an array return the indexes of a subarray which need to be sorted to make the whole array sorted

bool outOfOrder(vector<int> &arr, int i)
{

    if (i == 0)
    {
        return arr[i] > arr[i + 1];
    }
    else if (i == arr.size() - 1)
    {
        return arr[i] < arr[i - 1];
    }
    else
    {
        return arr[i] < arr[i - 1] or arr[i] > arr[i + 1];
    }
}

vector<int> solve(vector<int> &arr)
{
    // 1) Approach 1 is sort and compare O(NlogN)
    // 2) Approach 2 is O(N)
    int len = arr.size();
    int big = INT_MIN, small = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            big = max(big, arr[i]);
            small = min(small, arr[i]);
        }
    }

    if (small == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0, right = len - 1;
    while (small >= arr[left])
        left++;
    while (big <= arr[right])
        right--;
    return {left, right};
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    vector<int> ans = solve(arr);
    cout << ans[0] << " " << ans[1];
}