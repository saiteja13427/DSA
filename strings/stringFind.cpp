#include <bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big, string small)
{
    // store the occurrences in the result vector
    vector<int> result;

    // Looping to find it
    int len = big.length();
    int position = big.find(small);
    while (position != -1)
    {
        result.push_back(position);
        position = big.find(small, position + 1);
    }
    return result;
}

int main()
{
    string big = "I am a  boy but i am not a  boy because i am a ";
    string small = "good";
    vector<int> positions = stringSearch(big, small);
    if (positions.size() == 0)
        cout << "No occurences";
    for (int position : positions)
    {
        cout << position << endl;
    }
}