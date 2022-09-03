/*
    I/P: arr[] = {3, 8, 12, 5, 6}, n = 5
    O/P: 12
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int findLargest(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > res)
        {
            res = arr[i];
        }
    }

    return res;
}

int main()
{
    int arr[] = {3, 8, 12, 5, 6}, n = 5;

    cout << "Largest Element in Array: " << findLargest(arr, n);
}
