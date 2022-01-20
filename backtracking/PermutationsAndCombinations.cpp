#include <bits/stdc++.h>
using namespace std;

vector<string> combos;

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void pandc(char input[], int i, int n)
{
    if (input[i] == '\0')
    {
        string combination = string(input);
        combos.push_back(combination.substr(0, i));
        cout << endl;
        return;
    }

    string combination = string(input);
    combos.push_back(combination.substr(0, i));

    cout << endl;
    for (int it = i; it < n; it++)
    {
        swap(input[i], input[it]);
        pandc(input, i + 1, n);
        swap(input[i], input[it]);
    }
}

int main()
{
    int n;
    cin >> n;
    char input[100];
    cin >> input;
    pandc(input, 0, n);
    sort(combos.begin(), combos.end(), compare);
    for (int it = 0; it < combos.size(); it++)
    {
        cout << combos[it] << endl;
    }
}