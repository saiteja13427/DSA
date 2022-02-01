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
void sortedSubsequences(char *input, char seq[], int i, int j)
{
    if (input[i] == '\0')
    {
        if (j != 0)
        {
            seq[j] = '\0';
            string s = seq;
            subseq.push_back(s);
        }
        return;
    }
    seq[j] = input[i];
    sortedSubsequences(input, seq, i + 1, j + 1);
    sortedSubsequences(input, seq, i + 1, j);
}

int main()
{
    char input[] = "abcd";
    char seq[strlen(input) + 1];
    sortedSubsequences(input, seq, 0, 0);
    sort(begin(subseq), end(subseq), compare);
    for (string str : subseq)
        cout << str << endl;
}