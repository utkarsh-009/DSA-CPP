/*
    Input: N = 5, arr[] = {2, 4, 1, 3, 5}
    Output: 3
    Explanation: The sequence 2, 4, 1, 3, 5
    has three inversions (2, 1), (4, 1), (4, 3).

    Input: N = 5, arr[] = {2, 3, 4, 5, 6}
    Output: 0
    Explanation: As the sequence is already
    sorted so there is no inversion count.
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(nlogn), AS: O(n)]
int countAndMerge(int arr[], int l, int m, int r) // Simillar to merge function
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + l];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[m + 1 + j];
    }

    int res = 0, i = 0, j = 0, k = l; // res is total no of inversions
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[i]) // No inversion
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else // When inversion is possible
        {
            arr[k] = right[j];
            j++;
            k++;
            res = res + (n1 - i); // Calculating total inversion for left[i] > right[i]
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int effCountInversion(int arr[], int l, int r) // Simillar to mergeSort function
{
    int res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;
        res += effCountInversion(arr, l, m);     // Recursively counting inversion and sorting left sub array
        res += effCountInversion(arr, m + 1, r); // Recursively counting inversion and sorting right sub array
        res += countAndMerge(arr, l, m, r);      // Recursively counting inversion and merging left and right subarray
    }
    return res;
}

int main()
{

    int arr[] = {2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << effCountInversion(arr, 0, n - 1);
}