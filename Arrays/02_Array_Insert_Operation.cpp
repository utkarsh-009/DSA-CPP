/*
    I/P: arr = {5,24,64,2,7} , x = 34, pos = 2
    O/P: {5, 24, 34, 64, 2, 7}
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS:O(1)] => Worst Case: Insert At Begining, Best Case: Insert At End
int insert(int arr[], int n, int x, int cap, int pos)
{
    if (n == cap)
    {
        return -1;
    }

    for (int i = pos + 1; i <= n; i++)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = x;

    return n + 1;
}

int main()
{

    int arr[5], cap = 5, n = 3;

    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 20;

    cout << "Before Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int x = 7, pos = 2;

    n = insert(arr, n, x, cap, pos);

    cout << "After Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
