#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> subs;

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

void subsets(char input[], char output[], int i, int j)
{
    if (input[i] == '\0')
    {
        output[j] = '\0';
        string s = output;
        subs.push_back(s);
        return;
    }

    output[j] = input[i];
    subsets(input, output, i + 1, j + 1);
    subsets(input, output, i + 1, j);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char input[100];
        cin >> input;
        char output[100];
        subsets(input, output, 0, 0);
        //Lengthwise printing the subsets
        sort(subs.begin(), subs.end(), compare);
        for (int i = 0; i < subs.size(); i++)
        {
            cout << subs[i] << endl;
        }
    }
}