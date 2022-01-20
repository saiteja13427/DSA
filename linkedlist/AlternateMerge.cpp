// https://www.udemy.com/course/cpp-data-structures-algorithms-prateek-narang/learn/quiz/5293152#overview
#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List l1, l2;
    int k = 3;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);

    l2.pushBack(4);
    l2.pushBack(5);
    l2.pushBack(6);

    Node *itr1 = l1.begin(), *itr1next = l1.begin(), *itr2 = l2.begin(), *itr2next = l2.begin();
    while (itr1next != NULL && itr2next != NULL)
    {
        itr1next = itr1next->next;
        itr2next = itr2next->next;
        itr1->next = itr2;
        if (itr1next)
            itr2->next = itr1next;
        itr1 = itr1next;
        itr2 = itr2next;
    }

    itr1 = l1.begin();
    while (itr1 != NULL)
    {
        cout << itr1->getData() << endl;
        itr1 = itr1->next;
    }
}