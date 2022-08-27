#include <bits/stdc++.h>
using namespace std;

/*
I/P:
1 2 3
5 6 7
9 10 11


O/P:
3 7 11
2 6 10
1 5 9
*/

const int R = 3, C = 3;
void matRotate90(int mat[R][C]) // (Matrix -> Transpose -> Reverse all indivdual columns => Matrix Rotated by 90deg )
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i + 1; j < C; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < R; i++)
    {
        int low = 0, high = C - 1;
        while (low < high)
        {
            swap(mat[low], mat[high]);
            low++;
            high--;
        }
    }
}

void prntMat(int arr[R][C])
{
    cout << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3},
                     {5, 6, 7},
                     {9, 10, 11}};

    prntMat(arr);
    matRotate90(arr);
    prntMat(arr);
}