#include <bits/stdc++.h>
using namespace std;

// Not using count as it is reserved in imported ibs
int counter = 0;

bool canPlace(int board[][20], int i, int j, int n)
{
    int x = i, y = j;
    while (x--)
    {
        if (board[x][j] == 1)
        {
            return false;
        }
    }

    x = i, y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = i, y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}

void printBoard(int board[][20], int n)
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

void nQueens(int board[][20], int i, int n)
{
    // Base Case
    if (i == n)
    {
        counter++;
        // printBoard(board, n);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, i, j, n))
        {
            board[i][j] = 1;
            nQueens(board, i + 1, n);
        }
        board[i][j] = 0;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int board[20][20] = {0};
    auto start_time = clock();
    nQueens(board, 0, n);
    auto end_time = clock();
    cout << counter << endl;
    cout << (double)(end_time - start_time) << endl;
}