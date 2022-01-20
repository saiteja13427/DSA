#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    heap<int> h1(false, 10);
    h1.push(1);
    h1.push(10);
    h1.push(20);
    h1.push(4);
    h1.push(5);
    h1.push(100);
    h1.push(40);
    h1.push(2);
    h1.push(50);

    while (!h1.isEmpty())
    {
        cout << h1.top() << endl;
        h1.pop();
    }
}
