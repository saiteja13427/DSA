//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<int> s;
    vector<int> input = {4, 5, 2, 25}, ngt;

    for (int i = 0; i < input.size(); i++)
    {
        while (!s.empty() && s.top() < input[i])
        {
            ngt.push_back(input[i]);
            s.pop();
        }
        s.push(input[i]);
    }

    while (!s.empty())
    {
        ngt.push_back(-1);
        s.pop();
    }

    for (auto &a : ngt)
        cout << a << endl;
}