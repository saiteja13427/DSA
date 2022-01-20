#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Compare
{
public:
    // We are overloading the round brackets, i.e whenever two objects of this class are used with round brackets
    // This function will be called instead of default operation
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    int arr[6] = {90, 10, 20, 1, 5, 4};

    // Max Heap
    priority_queue<int> heap;

    for (auto &x : arr)
    {
        heap.push(x);
    }

    cout << "Max Heap" << endl;

    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    // Min Heap
    // Min heap declaration in c++
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (auto &x : arr)
    {
        minHeap.push(x);
    }

    cout << "Min minHeap" << endl;

    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    // Custom comparator Heap
    // Min heap declaration in c++
    priority_queue<int, vector<int>, Compare> customHeap;

    for (auto &x : arr)
    {
        customHeap.push(x);
    }

    cout << "Min minHeap" << endl;

    while (!customHeap.empty())
    {
        cout << customHeap.top() << " ";
        customHeap.pop();
    }
    cout << endl;
}
