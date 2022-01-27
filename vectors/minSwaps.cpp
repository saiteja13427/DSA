#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

// Find minimum swaps to be made to sort an array

int solve(vector<int> &arr)
{
    // Sort the array by also knowing the actual position of the element in the array
    int len = arr.size();
    vector<pair<int, int>> ap(len);
    for (int i = 0; i < len; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }
    // Sorting
    sort(begin(ap), end(ap));

    // LOGIC
    vector<bool> visited(len, false);
    int count = 0, ans = 0;
    for (int i = 0; i < len; i++)
    {
        // If it is visited or is at the correct position, skip
        int old_position = ap[i].second;
        if (visited[i] or old_position == i)
            continue;

        // Find cycle length
        int k = i;
        while (visited[k] == false)
        {
            visited[k] = true;
            k = ap[k].second;
            count++;
        }
        ans += count - 1;
        count = 0;
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 4, 1, 5, 3};
    cout << solve(arr);
}