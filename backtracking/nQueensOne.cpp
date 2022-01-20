#include <bits/stdc++.h>
using namespace std;

bool canPlace(int n, int board[][20], int i, int j)
{
    //Column
    for (int k = i - 1; k >= 0; k--)
    {
        if (board[k][j] == 1)
            return false;
    }

    int k = i, l = j;
    while (k >= 0 and l >= 0)
    {
        if (board[k][l] == 1)
        {
            return false;
        }
        k--;
        l--;
    }

    k = i, l = j;
    while (k >= 0 and l < n)
    {
        if (board[k][l] == 1)
        {
            return false;
        }
        k--;
        l++;
    }

    return true;
}

void print(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueens(int n, int board[][20], int i)
{
    if (i == n)
    {
        print(n, board);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(n, board, i, j))
        {
            board[i][j] = 1;
            if (solveNQueens(n, board, i + 1))
            {
                return true;
            }
        }
        board[i][j] = 0;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    int board[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    solveNQueens(n, board, 0);
}