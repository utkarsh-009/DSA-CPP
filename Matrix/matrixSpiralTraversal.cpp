#include <bits/stdc++.h>
using namespace std;

/*
I/P:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

O/P:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

const int R = 4, C = 4;
void prntSpiral(int mat[R][C])
{
    int top = 0, left = 0, bottom = R - 1, right = C - 1;//Maintaining 4 variables
    while (top <= bottom && left <= right)
    {
        // Top Row
        for (int i = left; i <= right; i++)
        {
            cout << mat[top][i] << " ";
        }
        top++;

        // Right Column
        for (int i = top; i <= bottom; i++)
        {
            cout << mat[i][right] << " ";
        }
        right--;

        // Bottom Row (Reverse Order)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }

        // Left Column(Reverse Order)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    prntSpiral(arr);
}