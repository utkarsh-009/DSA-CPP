/*
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

    I/P: 3
    O/P: No

    I/P:  4
    O/P:
    { 0,  1,  0,  0}
    { 0,  0,  0,  1}
    { 1,  0,  0,  0}
    { 0,  0,  1,  0}
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
bool isSafe(int row, int col, int N, vector<vector<int>> board)
{
    for (int i = 0; i < col; i++) // Checking each cell of row, if there already exist Queen => return false;
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // Checking only diagonals in which we have already place queens
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool helper(int col, int N, vector<vector<int>> &board)
{
    if (col == N) // If Nth Queen is placed => return true;
    {
        return true;
    }

    //
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, N, board))
        {
            board[i][col] = 1;

            if (helper(col + 1, N, board))
            {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void NQueen(vector<vector<int>> &board, int N)
{
    if (helper(0, N, board) == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int N = 4;
    vector<vector<int>> board(N, vector<int>(N, 0));
    NQueen(board, N);
}
