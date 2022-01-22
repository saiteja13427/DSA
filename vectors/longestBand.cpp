#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve(vector<int> &nums)
{
    // SORTING APPROACH
    //  sort(begin(nums), end(nums));
    int len = nums.size();
    // if(len==0) return 0;
    // int longest = 0, count=1;
    // for(int i=1; i<len; i++){
    //     if(nums[i] == nums[i-1]){
    //         continue;
    //     }else if(nums[i] - nums[i-1]!=1){
    //         longest = max(longest, count);
    //         count=1;
    //     }else{
    //         count++;
    //     }
    // }
    // return max(longest, count);

    // HASHMAP APPROACH
    unordered_map<int, int> el;
    int longest = 0;
    for (int i = 0; i < len; i++)
    {
        el[nums[i]]++;
    }

    for (int i = 0; i < len; i++)
    {
        if (!el[nums[i] - 1])
        {
            int count = 1;
            int num = nums[i] + 1;
            while (el[num])
                count++, num++;
            longest = max(count, longest);
        }
    }

    return longest;
}

int main()
{
    vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << solve(arr);
}