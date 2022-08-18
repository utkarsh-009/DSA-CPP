#include <bits/stdc++.h>
using namespace std;

/*
I/P:
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
x = 29

O/P:
Found at 3,2
*/

const int R = 4, C = 4;
void searchInRowColumnSortedMatrix1(int mat[R][C], int x)
{
    int i = 0, j = 0;
    for (j = C - 1; j >= 0; j--)
    {
        if (mat[i][j] == x)
        {
            cout << "Found at " << i + 1 << " " << j + 1 << endl;
            return;
        }
        else if (mat[i][j] < x) // If element < x => element not present in row
        {
            break;
        }
    }

    // Now look into the column
    for (i = 0; i < R; i++)
    {
        if (mat[i][j] == x)
        {
            cout << "Found at " << i + 1 << " " << j + 1 << endl;
            return;
        }
        else if (mat[i][j] > x) // if element > x => element not present in column
        {
            break;
        }
    }
    cout << "Not Found" << endl;
}

void searchInRowColumnSortedMatrix2(int mat[R][C], int x) // Efficient TC: O(R+C)
{
    // Start from Top Right Corner
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (mat[i][j] == x)
        {
            cout << "Found at (" << i + 1 << ", " << j + 1 << ")" << endl;
            return;
        }
        else if (mat[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "Not Found" << endl;
}

int main()
{
    int mat[R][C] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};

    searchInRowColumnSortedMatrix1(mat, 29);
    searchInRowColumnSortedMatrix1(mat, 19);
    searchInRowColumnSortedMatrix1(mat, 50);

    searchInRowColumnSortedMatrix2(mat, 29);
    searchInRowColumnSortedMatrix2(mat, 19);
    searchInRowColumnSortedMatrix2(mat, 50);
}