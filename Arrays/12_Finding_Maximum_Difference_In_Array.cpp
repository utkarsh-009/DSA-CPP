/*
Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.

    I/P: arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
    O/P: 8 (10-2)
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int maxDiff(int arr[], int n)
{
    int maxD = arr[1] - arr[0], minVal = arr[0]; // minVal will be ideal arr[i] to find max difference
    for (int j = 1; j < n; j++)
    {
        // Updating the maxDifference everytime by checking maximum between current maxDiff and difference of current element and minimum value
        maxD = max(maxD, arr[j] - minVal);

        // Updating minVal everytime by checking minimmum between current minVal and current element
        minVal = min(minVal, arr[j]);
    }

    return maxD;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
    cout << maxDiff(arr, n);
}
