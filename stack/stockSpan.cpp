// Link to problem: https://www.udemy.com/course/cpp-data-structures-algorithms-prateek-narang/learn/lecture/26674816#overview

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<vector<int>> s;
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85}, stockSpan = {1};

    vector<int> temp = {0, stock[0]};
    s.push(temp);

    for (int i = 1; i < stock.size(); i++)
    {
        if (!s.empty() and stock[i] > s.top()[1])
        {
            while (stock[i] > s.top()[1])
            {
                s.pop();
            }
        }
        stockSpan.push_back(i - s.top()[0]);
        vector<int> temp = {i, stock[i]};
        s.push(temp);
    }

    for (int i = 0; i < stockSpan.size(); i++)
    {
        cout << stockSpan[i] << endl;
    }
}