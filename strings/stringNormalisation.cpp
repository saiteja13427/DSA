#include <bits/stdc++.h>
using namespace std;

// THIS is SO mUCH
// This Is So Much

string normalize(const string &s)
{
    int len = s.length();
    string t;
    t += toupper(s[0]);
    for (int i = 1; i < len; i++)
    {
        if (s[i - 1] == ' ')
            t += toupper(s[i]);
        else if (s[i] != ' ')
            t += towlower(s[i]);
        else
            t += s[i];
    }
    return t;
}

int main()
{
    string s = "0123456791234567";
    s += 'f';
    cout << s.capacity() << endl;
    cout << normalize(s);
}