#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr)
{
    int largest = 0, counter = 0;
    int len = arr.size();
    for (int i = 1; i < len - 1; i++)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            int k = i;
            counter = 1;
            while (k >= 1 and arr[k] > arr[k - 1])
            {
                counter++;
                k--;
            }
            while (i < len - 1 and arr[i] > arr[i + 1])
            {
                counter++;
                i++;
            }
        }
        if (counter > max)
            max = counter;
    }

    cout << max << endl;
}

int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    solve(arr);
}