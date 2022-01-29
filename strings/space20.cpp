#include <bits/stdc++.h>
using namespace std;

// Replace all spaces in a string with %20

char *solve(char *s)
{
    // O(N) Time O(N) Space
    //  string a = "";
    //  for (int i = 0; i < s.size(); i++)
    //  {
    //      if (s[i] == ' ')
    //          a += "%20";
    //      else
    //          a += s[i];
    //  }
    //  return a;

    // O(N) Time O(1) Space
    // Calculating number of spaces and transferring characters from end to len + spaces*2 -1 positions
    // And if we see space we put in %,2,0 at three preceding positions
    int spcs = 0;
    int len = strlen(s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
            spcs++;
    }

    int index = len + (2 * spcs);
    s[index] = '\0';
    index--;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[index] = '0';
            index--;
            s[index] = '2';
            index--;
            s[index] = '%';
            index--;
        }
        else
        {
            s[index] = s[i];
            index--;
        }
    }
    return s;
}

int main()
{
    char s[1000];
    cin.getline(s, 1000);
    solve(s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        cout << s[i];
    }
}