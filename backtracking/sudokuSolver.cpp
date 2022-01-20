#include <bits/stdc++.h>
using namespace std;

// Printing the sudoku board
void printSudoku(int sudoku[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Checking if it is safe to place a number or not by checking row, column and the
// grid
bool canPlace(int sudoku[][20], int i, int j, int n, int num)
{

    int x = n, y = j;
    // Checking column
    while (x--)
    {
        if (sudoku[x][y] == num)
            return false;
    }

    // Checking row
    x = i, y = n;
    while (y--)
    {
        if (sudoku[x][y] == num)
            return false;
    }

    // Checking 3*3 grid
    x = ((i) / 3) * 3, y = ((j) / 3) * 3;
    for (int m = x; m < x + 3; m++)
    {
        for (int n = y; n < y + 3; n++)
        {
            if (sudoku[m][n] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int sudoku[][20], int i, int j, int n)
{
    // Base Case
    if (i == n)
    {
        printSudoku(sudoku, n);

        return true;
    }

    // As we are going to end of a row, then to go to the next row
    if (j == n)
    {
        return solveSudoku(sudoku, i + 1, 0, n);
    }

    // If a cell is filled, we just skip it
    if (sudoku[i][j] != 0)
    {
        return solveSudoku(sudoku, i, j + 1, n);
    }

    // Placing 1-9 in unfilled cell and calling subproblem on every placement and checking if it is true ot not
    for (int num = 1; num <= 9; num++)
    {
        if (canPlace(sudoku, i, j, n, num))
        {
            sudoku[i][j] = num;
            bool success;
            success = solveSudoku(sudoku, i, j + 1, n);
            if (success)
                return true;
            sudoku[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int sudoku[20][20] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    solveSudoku(sudoku, 0, 0, n);
}