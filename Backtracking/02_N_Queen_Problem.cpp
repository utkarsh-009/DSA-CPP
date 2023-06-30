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

// Q1: IMP APPROACH Printing all distinct solutions to the n-queens puzzle.
class Solution
{
public:
    // checking if queen is present or not
    bool isSafe(vector<string> &board, int r, int c)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            if (board[r][i] == 'Q' || board[i][c] == 'Q')
            {
                return false;
            }
        }

        for (int i = 0, j = 0; i < n && j < n; i++, j++)
        {
            if (r + i < n && c + j < n)
                if (board[r + i][c + j] == 'Q')
                {
                    return false;
                }

            if (r - i >= 0 && c + j < n)
                if (board[r - i][c + j] == 'Q')
                {
                    return false;
                }

            if (r + i < n && c - j >= 0)
                if (board[r + i][c - j] == 'Q')
                {
                    return false;
                }

            if (r - i >= 0 && c - j >= 0)
                if (board[r - i][c - j] == 'Q')
                {
                    return false;
                }
        }

        return true;
    }

    void helper(vector<string> &board, vector<vector<string>> &ans, int r, int c, int q)
    {
        int n = board.size();
        if (q == n)
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(board, i, c))
            {
                board[i][c] = 'Q';
                helper(board, ans, i, c + 1, q + 1);
                board[i][c] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        string str;
        str.append(n, '.');
        vector<string> board(n, str);

        vector<vector<string>> ans;
        helper(board, ans, 0, 0, 0);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(N!)
Auxiliary Space: O(N*N)
*/
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
