#include <bits/stdc++.h>
using namespace std;

// Split string into tokens separated by delimiter

// strtok returns the pointer to the first word
void solve(char *s)
{
    char *a = strtok(s, " ");
    while (a)
    {
        cout << a << endl;
        // We pass NULL here as we want the next word of the string.
        // strtok stores the state of previous string passed to the function using static variables
        a = strtok(NULL, " ");
    }
}

int main()
{
    char s[1000] = "I am a good boy";
    // cout << s << endl;
    solve(s);
}