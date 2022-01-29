#include <bits/stdc++.h>
using namespace std;

// Split string into tokens separated by delimiter
// Custom string tokenizer which behaves like strtok inbuilt function

char *mystrtok(char *s, char delim)
{
    // This static variable stores the state of the string
    static char *input = NULL;
    if (s != NULL)
        input = s;

    if (input == NULL)
        return NULL;

    // Token will store the current word
    char *token = new char[strlen(input) + 1];
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        // Once we get delimiter we return token and point static input to character after space
        if (input[i] == delim)
        {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
        token[i] = input[i];
    }
    // At the end we put another null character, put input =NULL and return last token
    // After this it the function will return NULL to tell that we are at the end of the string
    input[i] = '\0';
    input = NULL;
    return token;
}

int main()
{
    char s[1000] = "I am Sai Teja";

    char *a = mystrtok(s, ' ');
    while (a)
    {
        cout << a << endl;
        a = mystrtok(NULL, ' ');
    }
}