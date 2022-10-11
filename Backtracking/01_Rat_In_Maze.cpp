/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e.,
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination.
The rat can move only in two directions: forward and down.

    I/P:
    {1, 0, 0, 0}
    {1, 1, 0, 1}
    {0, 1, 0, 0}
    {1, 1, 1, 1}

    O/P:
    Yes
    {1, 0, 0, 0}
    {1, 1, 0, 0}
    {0, 1, 0, 0}
    {0, 1, 1, 1}

    I/P:
    {1, 0, 0, 0}
    {1, 1, 0, 1}
    {0, 0, 0, 0}
    {1, 1, 1, 1}
    O/P:
    No
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(2^(n^2)).
    The recursion can run upper-bound 2^(n^2) times.
    Space Complexity: O(n^2).
    Output matrix is required so an extra space of size n*n is needed.
*/
bool isSafe(int i, int j, int N, vector<vector<int>> maze)
{
    return (i < N && j < N && maze[i][j] == 1);
}

bool helper(int i, int j, int N, vector<vector<int>> maze, vector<vector<int>> &mazePath)
{
    if (i == N - 1 && j == N - 1 && maze[i][j] == 1)
    {
        mazePath[i][j] = 1;
        return true;
    }

    if (isSafe(i, j, N, maze))
    {
        mazePath[i][j] = 1;
        if (helper(i, j + 1, N, maze, mazePath))
        {
            return true;
        }
        if (helper(i + 1, j, N, maze, mazePath))
        {
            return true;
        }

        mazePath[i][j] = 0;
    }

    return false;
}

void solveRatMaze(int N, vector<vector<int>> maze)
{
    vector<vector<int>> mazePath(N, vector<int>(N, 0));
    if (helper(0, 0, N, maze, mazePath) == false)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < mazePath.size(); i++)
        {
            for (int j = 0; j < mazePath[0].size(); j++)
            {
                cout << mazePath[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> maze{{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {0, 1, 0, 0},
                             {1, 1, 1, 1}};

    solveRatMaze(n, maze);
}
