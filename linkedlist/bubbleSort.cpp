#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List l1;
    l1.pushBack(10);
    l1.pushBack(30);
    l1.pushBack(20);
    l1.pushBack(5);

    int len = 0;
    Node *itr = l1.begin(), *itr2;
    while (itr != NULL)
    {
        len++;
        itr = itr->next;
    }

    while (len--)
    {
        itr = l1.begin();
        itr2 = itr->next;
        while (itr2 != NULL)
        {
            if (itr->data > itr2->data)
            {
                int temp = itr->data;
                itr->data = itr2->data;
                itr2->data = temp;
            }
            itr = itr2;
            itr2 = itr2->next;
        }
    }
    itr = l1.begin();
    while (itr != NULL)
    {
        cout << itr->data << endl;
        itr = itr->next;
    }
}
