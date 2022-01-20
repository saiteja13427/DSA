#include <iostream>
#include <vector>
using namespace std;

void square(int n)
{
    // int s = (2 * n) - 1;
    // vector<vector<int>> pattern(s, vector<int>(s, n));
    // int move = 0;
    // for (int i = n; i > 0; i--)
    // {
    //     for (int j = move; j < s - move; j++)
    //     {
    //         pattern[move][j] = i;
    //     }
    //     move++;
    // }

    // move = s - 1;
    // for (int i = n; i > 1; i--)
    // {
    //     for (int j = move; j >= s - 1 - move; j--)
    //     {
    //         pattern[move][j] = i;
    //     }
    //     move--;
    // }

    // for (int i = 0; i < s; i++)
    // {
    //     for (int j = 0; j < s; j++)
    //     {
    //         cout << pattern[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // BETTER SMALLER SOLUTION
    int originalN = n;
    n = 2 * n - 2;
    for (int row = 0; row <= n; row++)
    {
        for (int col = 0; col <= n; col++)
        {
            int curr = originalN - min(min(row, col), min(n - row, n - col));
            cout << curr << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    square(4);
}