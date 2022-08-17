#include <bits/stdc++.h>
using namespace std;
/*
NOTE:
In C++ mutli-dimensional matrix elements are stored row-major order i.e. row format

*/
void prntMat(int arr[2][2])
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

int main()
{
    int arr[2][2] = {{10, 2}, {4, 25}};
    // also can be written as arr[][2] = {{10, 2}, {4, 25}}; i.e. we can ignore the first dimension while defining, as compiler automatically intreprets its dimensions
    // also can be written as arr[2][2] = {10, 2, 4, 25}; i.e. we can ignore the brackets while initialising the matrix, as compiler automatically intreprets its dimensions

    // Ways to create multidimensinal array
    // M1: Variable Sized
    int m1 = 3, n1 = 2;
    int arr1[m1][n1];

    // M2: Double Pointer
    /*
    P1 -> A1[n1]
    P2 -> A2[n2]
    P3 -> A3[n3]
    P4 -> A4[n4]
    Adv: Can create dynamic array; DisAdv: If created size of arrays are different then there will be cache misses
    */
    int m2 = 3, n2 = 2;
    int **arr2;           // pointer pointing to dynamically allocated memory.
    arr2 = new int *[m2]; // No of pointers in that dynamically allocated memory.
    for (int i = 0; i < m2; i++)
    {
        arr2[i] = new int[n2]; // Dynamically allocating size of array for every array pointer
    }

    // M3: Array of Pointers
    // Difference betn M2 & M3, in M3 we are creating array of pointers and in M2 we had pointer that was pointing to dynamically allocated memory arr.
    int m3 = 3, n3 = 2;
    int *arr3[m3];
    for (int i = 0; i < m3; i++)
    {
        arr3[i] = new int[n3];
    }

    // M4: Array of Vectors (Arrays stored in vector)
    int m4 = 3, n4 = 2;
    vector<int> arr4[m4];

    // M5: Vector of Vectors
    int m5 = 3, n5 = 2;
    vector<vector<int>> arr5(m5, vector<int>(n5));
}