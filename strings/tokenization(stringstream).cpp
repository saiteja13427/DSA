#include <bits/stdc++.h>
using namespace std;

// Split string into tokens separated by delimiter

void solve(string s)
{
    stringstream ss(s);

    string token;
    while (getline(ss, token, ' '))
    {
        cout << token << endl;
    }
}

int main()
{
    string s = "I am a good boy";
    solve(s);
}