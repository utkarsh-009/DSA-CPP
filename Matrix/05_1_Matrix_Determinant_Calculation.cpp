/*
Input:
N = 4
matrix[][] = {{1, 0, 2, -1},
              {3, 0, 0, 5},
              {2, 1, 4, -3},
              {1, 0, 5, 0}}
Output: 30
*/

#include <bits/stdc++.h>
using namespace std;

int determinantOfMatrix(vector<vector<int>> matrix, int n)
{
    // Base Cases
    if (n == 1)
    {
        return matrix[0][0];
    }
    else if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) // Finding determinant value of sub-matrix for every element of 1st row of matrix
    {
        vector<vector<int>> temp;   // sub matrix
        for (int j = 1; j < n; j++) // As, 1st row used for determinant calculation => 1st column is ignored. Hence, iteration starts from j = 1
        {
            vector<int> v;
            for (int k = 0; k < n; k++)
            {
                if (k == i) // Ignoring the column in which element lies
                    continue;
                else
                {
                    v.push_back(matrix[j][k]);
                }
            }
            temp.push_back(v);
        }

        if (i % 2 != 0)
        {
            ans -= (matrix[0][i]) * determinantOfMatrix(temp, n - 1); // Recursievly calling calculating value of sub matrix and finding determinant value
        }
        else
        {
            ans += (matrix[0][i]) * (determinantOfMatrix(temp, n - 1)); // Recursievly calling calculating value of sub matrix and finding determinant value
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 2, -1},
                               {3, 0, 0, 5},
                               {2, 1, 4, -3},
                               {1, 0, 5, 0}};

    cout << "Determinant of the matrix is : " << determinantOfMatrix(mat, 4);
    return 0;
}
