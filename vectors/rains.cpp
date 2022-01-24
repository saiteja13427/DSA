#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given heights of buildings find how much water can be blocked between them.

int solve(vector<int> &h)
{
    int len = h.size();
    vector<int> left(len), right(len);
    int maxHeight = h[0];
    for (int i = 0; i < len; i++)
    {
        if (h[i] > maxHeight)
            maxHeight = h[i];
        left[i] = maxHeight;
    }
    maxHeight = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (h[i] > maxHeight)
            maxHeight = h[i];
        right[i] = maxHeight;
    }

    int sumWater = 0;
    for (int i = 0; i < len; i++)
    {
        sumWater += min(left[i], right[i]) - h[i];
    }

    return sumWater;
}

int main()
{
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << solve(h);
}