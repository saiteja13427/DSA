#include <iostream>
#include "stackLL.h"
using namespace std;

int main()
{

    Stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');

    while (!s.isEmpty())
    {
        cout << s.getTop();
        s.pop();
    }
}