#include <bits/stdc++.h>
int R = 3, C = 2; // GLOBAL VARIABLES
using namespace std;

// M1: Specifying both dimensions
void prntMat1(int arr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// M2: Omiting the first dimension of the matrix
void prntMat2(int arr[][2], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// M3: Use of Global Variables
void prntMat3(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// C-STYLE SOLUTIONS //
// M4: Using Double Pointer (NOTE: Matrix allocation should be done using double pointer OR using pointer to pointer)
void prntMat4(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// M5: Using Array of Pointer (NOTE: Matrix should be created using  array of pointers)
void prntMat5(int *arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

// M6: Using Array of vectors (NOTE: Matrix should be created using Array of Vectors)
void prntMat6(vector<int> arr[], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// M7: Using Vectors of Vectors (NOTE: Matrix should be created using Vector of Vector)
void prntMat7(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
