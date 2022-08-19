#include <bits/stdc++.h>
using namespace std;

/*
I/P: 5 10 20 30 40
     1  2  3  4  6
     11 13 15 17 19
    (1,2,3,4,5,6,10,*11*,13,15,17,19,20,30,40)
O/P: 11

Dry Run:
medPos = (3*5 + 1)/2 = (16)/2 = 8

min= 1, max = 40
mid = 20
midPos = 3 + 5 + 5 = 13 (medPos < midPos) => max = mid

min = 1, max = 20
mid = 10
midPos = 2 + 5 + 0  = 7 (medPos > midPos) => min = mid + 1

mid = 11, max = 20
mid = 15
midPos = 2 + 5 + 3 = 10 (medPos < midPos) => max = mid

min = 11, max = 15
mid = 13
midPos = 2 + 5 + 2 = 9 (medPos < midPos) => max = mid

min = 11, max = 13
mid = 12
midPos = 2 + 5 + 1 = 8 (medPos = midPos) but (min != max) and 12 not present in matrix

min = 11, max = 12
mid = 11
midPos = 2 + 5 + 1 = 8 (medPos = midPos)

min = 11 and max = 11
*/

const int R = 3, C = 5;
int matMed(int mat[R][C], int r, int c) // TC: O(R*log(max-min)*logC)
{
    int min = mat[0][0], max = mat[0][C - 1];
    for (int i = 0; i < R; i++)
    {
        if (min < mat[i][0])
        {
            min = mat[i][0];
        }
        if (max > mat[i][C - 1])
        {
            max = mat[i][C - 1];
        }
    }

    int medPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (mid + max) / 2;
        int midPos = 0;
        for (int i = 0; i < R; i++)
        {
            midPos += upper_bound(mat[i], mat[i] + C, mid) - mat[i];
        }
        if (midPos < medPos)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }
    return min;
}

int main()
{
    int m[R][C] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    cout << "Median is " << matMed(m, R, C) << endl;
}