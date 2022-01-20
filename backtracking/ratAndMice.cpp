#include <bits/stdc++.h>
using namespace std;

bool solveMaze(char maze[][20], int solved[][20], int i, int j, int n, int m)
{
    if (i == n && j == m)
    {
        solved[i][j] = 1;
        return true;
    }
    // solveMaze(maze, solved, i + 1, j + 1, n, m);
    solved[i][j] = 1;
    if (i > 0 and maze[i - 1][j] != 'X' and solved[i - 1][j] != 1 and solveMaze(maze, solved, i - 1, j, n, m))
    {
        solved[i][j] = 1;
        return true;
    }
    if (i < n and maze[i + 1][j] != 'X' and solved[i + 1][j] != 1 and solveMaze(maze, solved, i + 1, j, n, m))
    {
        solved[i][j] = 1;
        return true;
    }
    if (j < m and maze[i][j + 1] != 'X' and solved[i][j + 1] != 1 and solveMaze(maze, solved, i, j + 1, n, m))
    {
        solved[i][j] = 1;
        return true;
    }
    if (j > 0 and maze[i][j - 1] != 'X' and solved[i][j - 1] != 1 and solveMaze(maze, solved, i, j - 1, n, m))
    {
        solved[i][j] = 1;
        return true;
    }
    solved[i][j] = 0;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    char maze[20][20];
    int solved[20][20] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = s[j];
        }
    }
    solveMaze(maze, solved, 0, 0, n - 1, m - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << solved[i][j] << " ";
        }
        cout << endl;
    }
}