#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> nums;
    stack<int> reverse;
    int num = 1024;

    while (num > 0)
    {
        nums.push(num % 10);
        num /= 10;
    }

    num = 0;
    int i = 1;

    while (!nums.empty())
    {
        num = num + nums.top() * i;
        nums.pop();
        i *= 10;
    }

    cout << num << endl;
}