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
    void update(vector<string> &board, vector<vector<int>> &vis, int r, int c)
    {
        board[r][c] = 'Q';
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            vis[i][c]++;
            vis[r][i]++;
        }

        for (int i = 0, j = 0; i < n && j < n; i++, j++)
        {
            if (r + i < n && c + j < n)
                vis[r + i][c + j]++;

            if (r - i >= 0 && c + j < n)
                vis[r - i][c + j]++;

            if (r + i < n && c - j >= 0)
                vis[r + i][c - j]++;

            if (r - i >= 0 && c - j >= 0)
                vis[r - i][c - j]++;
        }
    }

    void outdate(vector<string> &board, vector<vector<int>> &vis, int r, int c)
    {
        int n = board.size();
        board[r][c] = '.';
        for (int i = 0; i < n; i++)
        {
            vis[i][c]--;
            vis[r][i]--;
        }

        for (int i = 0, j = 0; i < n && j < n; i++, j++)
        {
            if (r + i < n && c + j < n)
                vis[r + i][c + j]--;

            if (r - i >= 0 && c + j < n)
                vis[r - i][c + j]--;

            if (r + i < n && c - j >= 0)
                vis[r + i][c - j]--;

            if (r - i >= 0 && c - j >= 0)
                vis[r - i][c - j]--;
        }
    }

    bool isSafe(int r, int c, int n, vector<vector<int>> &vis)
    {
        if (r < 0 || c < 0 || r >= n || c >= n || vis[r][c])
        {
            return false;
        }
        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> board, vector<vector<int>> &vis, int r, int c, int q)
    {
        int n = board.size();
        if (q == n)
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(i, c, n, vis))
            {
                update(board, vis, i, c);
                solve(ans, board, vis, i, c + 1, q + 1);
                outdate(board, vis, i, c);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        int cnt = 0;

        vector<string> board(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i].push_back('.');

        vector<vector<string>> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(ans, board, vis, 0, 0, 0);

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
