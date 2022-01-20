#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

void solve(vector<int> &arr, int target)
{
    // HASHMAP
    //  unordered_map<int, int> diff;
    int len = arr.size();
    //  for (int i = 0; i < len; i++)
    //  {
    //      if (diff[arr[i]])
    //          cout << arr[i] << " " << diff[arr[i]] << endl;
    //      diff[target - arr[i]] = arr[i];
    //  }

    // SET
    set<int> num;
    for (int i = 0; i < len; i++)
    {
        if (num.count(target - arr[i]))
            cout << arr[i] << " " << target - arr[i] << endl;
        num.insert(arr[i]);
    }
}

int main()
{
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int target = 4;
    solve(arr, target);
}