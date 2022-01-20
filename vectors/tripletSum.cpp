#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<vector<int>> solve(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    sort(begin(arr), end(arr));
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        vector<int> temp;
        int smallTarget = target - arr[i];
        for (int x = i + 1, y = len - 1; x < y;)
        {
            if (arr[x] + arr[y] > smallTarget)
                y--;
            else if (arr[x] + arr[y] < smallTarget)
                x++;
            else if (arr[x] + arr[y] == smallTarget)
            {
                ans.push_back({arr[i], arr[x], arr[y]});
                x++;
                y--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int target = 18;
    vector<vector<int>> ans = solve(arr, target);
    int len = ans.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}