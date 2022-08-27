#include <bits/stdc++.h>
using namespace std;

/*
I/P:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

O/P:
1 2 3 4 8 12 16 15 15 14 9 5
*/

const int R = 4, C = 4;
void prntBoundaryTrav(int mat[R][C])
{
    if (R == 1)
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[0][j] << " ";
        }
    }
    else if (C == 1)
    {
        for (int i = 0; i < R; i++)
        {
            cout << mat[i][0] << " ";
        }
    }
    else
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[0][j] << " ";
        }
        for (int i = 1; i < R; i++)
        {
            cout << mat[i][C - 1] << " ";
        }
        for (int j = C - 2; j > 0; j--)
        {
            cout << mat[R - 1][j] << " ";
        }

        for (int i = R - 2; i > 0; i--)
        {
            cout << mat[i][0] << " ";
        }
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    prntBoundaryTrav(arr);
}