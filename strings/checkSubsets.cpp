#include <bits/stdc++.h>
using namespace std;

// Check if child string is a subsequence of a parentstring

bool checkSubsets(string parent, string child)
{
    int plen = parent.size();
    int clen = child.size();
    int i, j;
    for (i = 0, j = 0; i < plen & j < clen; i++)
    {
        if (parent[i] == child[j])
            j++;
    }

    return j == clen;
}

int main()
{
    string parent = "codingminutes";
    string child = "cod";
    cout << (checkSubsets(parent, child) ? "YES" : "NO");
}