#include <iostream>
#include "queueArray.h"
using namespace std;

int main()
{
    Queue<int> q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();

    q.push(6);
    q.pop();

    q.push(7);

    while (!q.empty())
    {
        cout << q.f() << endl;
        q.pop();
    }
}