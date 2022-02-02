#include <bits/stdc++.h>
using namespace std;

string compressString(const string &str)
{
    // complete the function to return output string
    int len = str.length();
    int count = 1;
    string ans = "";
    for (int i = 1; i < len; i++)
    {
        if (str[i] != str[i - 1])
        {
            ans += str[i - 1] + to_string(count);
            count = 1;
        }
        else
        {
            count++;
        }
    }
    ans += str[len - 1] + to_string(count);
    if (ans.length() > len)
        return str;
    return ans;
}

int main()
{
    string s = "abc";
    cout << compressString(s);
}