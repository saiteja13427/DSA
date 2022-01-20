#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
    hashtable<int> h(5);
    h["apple"] = 12;
    h["mango"] = 15;
    h["banana"] = 20;
    h["grapes"] = 10;
    h["papaya"] = 120;

    h.print();
}