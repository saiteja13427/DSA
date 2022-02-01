#include <bits/stdc++.h>
using namespace std;

// Return sorted array of subsequences of a string sorted based on length then lexicographically
vector<string> subseq;

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}
void sortedSubsequences(string input, string output)
{
    if (input.size() == 0)
    {
        subseq.push_back(output);
        return;
    }
    char c = input[0];
    input = input.substr(1);
    sortedSubsequences(input, output + c);
    sortedSubsequences(input, output);
}

int main()
{
    string input = "abcd";
    sortedSubsequences(input, "");
    sort(begin(subseq), end(subseq), compare);
    for (string str : subseq)
        cout << str << endl;
}