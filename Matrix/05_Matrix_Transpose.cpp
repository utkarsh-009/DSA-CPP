#include <bits/stdc++.h>
using namespace std;

/*
I/P:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

O/P:
1 5 9 13
2 6 10 14
3 7 11 15
4 8 12 16
*/

const int R = 4, C = 4;
void prntTranspose(int mat[R][C])
{
    for (int j = 0; j < C; j++)
    {
        for (int i = 0; i < R; i++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void convertTraspose(int mat[R][C]) // Note that diagonal element of matrix remained unchanged in transpose of matrix
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i + 1; j < C; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    // prntTranspose(arr);
    convertTraspose(arr);
}