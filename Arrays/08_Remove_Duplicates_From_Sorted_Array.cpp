/*
    I/P: arr = {10,20,20,30,30,30,30}, n = 7
    O/P: {10,20,30}
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int removeDupFromSortedArr(int arr[], int n)
{
    int ind = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[ind] = arr[i];
            ind++;
        }
    }

    return ind;
}

int main()
{
    int arr[] = {10, 20, 20, 30, 30, 30}, n = 6;

    cout << "Before Removal" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    n = removeDupFromSortedArr(arr, n);

    cout << "After Removal" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
