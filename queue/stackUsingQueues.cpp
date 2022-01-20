#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    bool empty()
    {
        return q1.empty();
    }
    void push(int data)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop()
    {
        q1.pop();
    }

    int top()
    {
        return q1.front();
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.pop();

    s1.push(6);

    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}
