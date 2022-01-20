#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    arr.push_back(1);
    cout << arr.size() << endl;
    cout << arr.capacity() << endl;
}