#include <iostream>
#include "stackVec.h"
using namespace std;

void insertBottomRecursive(Stack<int> &s, int data)
{
    if (s.isEmpty())
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();
    insertBottomRecursive(s, data);
    s.push(temp);
}

void recursiveReverse(Stack<int> &s)
{
    if (s.isEmpty())
        return;

    int temp = s.top();
    s.pop();
    recursiveReverse(s);
    insertBottomRecursive(s, temp);
}

void insertBottom(Stack<int> &s, int data)
{
    Stack<int> temp;

    while (!s.isEmpty())
    {
        temp.push(s.top());
        s.pop();
    }

    s.push(data);

    while (!temp.isEmpty())
    {
        s.push(temp.top());
        temp.pop();
    }
}

int main()
{

    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    insertBottom(s, 0);

    recursiveReverse(s);

    while (!s.isEmpty())
    {
        cout << s.top();
        s.pop();
    }
}