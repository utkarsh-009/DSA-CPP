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
}

int main()
{
    int arr[R][C] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    prntSpiral(arr);
}