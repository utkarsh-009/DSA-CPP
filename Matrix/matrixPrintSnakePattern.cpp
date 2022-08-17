#include <bits/stdc++.h>
using namespace std;

/*
I/P:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

O/P:
1 2 3 4
8 7 6 5
9 10 11 12
16 15 14 13
*/
const int R = 4, C = 4;
void prntSnakePattern(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < C; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            for (int j = C - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    prntSnakePattern(arr);
}