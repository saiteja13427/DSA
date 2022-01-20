#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q1;
    int len = 10;
    q1.push(11);
    q1.push(12);
    q1.push(13);
    q1.push(14);
    q1.push(15);
    q1.push(16);
    q1.push(17);
    q1.push(18);
    q1.push(19);
    q1.push(20);

    int halfLen = len / 2;

    queue<int> q2;

    while (halfLen--)
    {
        q2.push(q1.front());
        q1.pop();
    }

    while (!q2.empty())
    {
        q1.push(q2.front());
        q1.push(q1.front());
        q1.pop();
        q2.pop();
    }

    while (!q1.empty())
    {
        cout << q1.front() << endl;
        q1.pop();
    }
}