#include <bits/stdc++.h>
using namespace std;

// Find longest sequence on nonoverlapping pairs

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int countActivites(vector<pair<int, int>> activities)
{
    // Complete this method
    // Sort the vector
    sort(begin(activities), end(activities), compare);
    int len = activities.size();
    int count = 1;
    int high = activities[0].second;
    // Starting from the beginning, find all the next non overlapping intervals
    for (int i = 1; i < len; i++)
    {
        if (activities[i].first >= high)
        {
            count++;
            high = activities[i].second;
        }
    }
    return count;
}

int main()
{
    vector<pair<int, int>> activities = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};
    cout << countActivites(activities);
}