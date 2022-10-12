/*
    I/P:
    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }

    O/P:
    3 1 6 5 7 8 4 9 2
    5 2 9 1 3 4 7 6 8
    4 8 7 6 2 9 5 3 1
    2 6 3 4 1 5 9 8 7
    9 7 4 8 6 3 1 2 5
    8 5 1 7 9 2 6 4 3
    1 3 8 9 4 7 2 5 6
    6 9 2 3 5 1 8 7 4
    7 4 5 2 8 6 3 1 9
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int row, int col, int num, int N)
{
    // To check for col in grid, if number is already placed => return false
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }

    // To check for row in grid, if number is already placed => return false
    for (int j = 0; j < N; j++)
    {
        if (grid[row][j] == num)
        {
            return false;
        }
    }

    // To check for subgrid, if number is already placed => return false
    int s = (int)sqrt(N);
    int startRow = row - row % s;
    int startCol = col - col % s;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool helper(int N, vector<vector<int>> &grid)
{
    int i, j;
    bool isEmpty = true;
    // To check if sudoku is already solved
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                isEmpty = false;
                break;
            }
        }

        if (!isEmpty)
        {
            break;
        }
    }

    // Condition of already solved sudoku
    if (isEmpty)
    {
        return true;
    }

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, i, j, num, N)) // Checking i, j as safe
        {
            grid[i][j] = num;
            if (helper(N, grid))
            {
                return true;
            }

            grid[i][j] = 0;
        }
    }

    return false;
}

void SudokuSolver(vector<vector<int>> &grid, int N)
{
    if (helper(N, grid) == true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }

            cout << endl;
        }
    }
}

int main()
{
    vector<vector<int>> grid{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int N = grid.size();
    SudokuSolver(grid, N);
}
