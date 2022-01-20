#include <bits/stdc++.h>
using namespace std;

bool canPlace(int board[][20], int i, int j, int n)
{
    int x = i, y;
    while (x--)
    {
        if (board[x][j] == 1)
            return false;
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

int nQueens(int board[][20], int i, int n)
{
    if (i == n)
    {
        return 1;
    }

    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, i, j, n))
        {
            board[i][j] = 1;
            ans += nQueens(board, i + 1, n);
        }
        board[i][j] = 0;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int board[20][20] = {0};
    cout << nQueens(board, 0, n) << endl;
}