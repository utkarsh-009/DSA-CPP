/*
    I/P: arr[] = {3, 8, 12, 5, 6}, n = 5
    O/P: NO

    I/P: arr[] = {24, 46, 75, 75, 87}, n = 5
    O/P: YES
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
bool isArraySorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr1[] = {3, 8, 12, 5, 6};
    int arr2[] = {24, 46, 75, 75, 87};
    int n = 5;

    ((isArraySorted(arr1, n)) ? cout << "YES" << endl : cout << "NO" << endl);
    ((isArraySorted(arr2, n)) ? cout << "YES" << endl : cout << "NO" << endl);
}
