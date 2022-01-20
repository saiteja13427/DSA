#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> permut;

void permutations(char input[], int i, int n)
{
    if (input[i] == '\0')
    {
        permut.push_back(input);
        return;
    }
    for (int k = i; k < n; k++)
    {
        swap(input[i], input[k]);
        permutations(input, i + 1, n);
        swap(input[i], input[k]);
    }
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
        permutations(input, 0, n);
        //Lengthwise printing the subsets
        cout << permut.size() << endl;
        for (int i = 0; i < permut.size(); i++)
        {
            cout << permut[i] << endl;
        }
    }
}