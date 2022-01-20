#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> outputs;

void uniqueSubSetsHelper(vector<int> nums, vector<int> output, int i)
{
    // Basecase

    if (i == nums.size())
    {
        outputs.push_back(output);
        return;
    }
    // Logic

    if (!output.empty() && output.back() == nums[i])
    {
        // outputs.push_back(output);
        output.push_back(nums[i]);
        uniqueSubSetsHelper(nums, output, i + 1);
    }
    else
    {

        output.push_back(nums[i]);
        uniqueSubSetsHelper(nums, output, i + 1);
        output.pop_back();
        uniqueSubSetsHelper(nums, output, i + 1);
    }
}

vector<vector<int>> uniqueSubSets(vector<int> nums)
{
    vector<int> output;
    int i = 0;
    int j = 0;
    uniqueSubSetsHelper(nums, output, i);
    return outputs;
}

int main()
{
    vector<int> nums = {0, 1, 4};
    uniqueSubSets(nums);
    for (int i = 0; i < outputs.size(); i++)
    {
        for (int j = 0; j < outputs[i].size(); j++)
        {
            cout << outputs[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}