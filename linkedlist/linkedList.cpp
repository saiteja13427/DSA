#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    List<int> l;
    l.push_front(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(12);

    l.pop_back();

    Node<int> *itr = l.begin();

    while (itr != NULL)
    {
        cout << itr->getData() << " ";
        itr = itr->next;
    }
    cout << endl;

    l.reverse();
    itr = l.begin();
    while (itr != NULL)
    {
        cout << itr->getData() << " ";
        itr = itr->next;
    }
    cout << endl;
    cout << l.search(2) << endl;
    cout << l.recursiveSearch(1) << endl;
}