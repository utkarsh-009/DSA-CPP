/*
    I/P: {5, 5, 10, 10, 10, 20}, n = 10
    O/P: 4

    I/P: {5, 10, 10, 10, 20}, n = 40
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n) ,AS: O(1)]
int lastOccNaive(int arr[], int n, int x)
{
    int ind = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            ind = i;
        }
    }

    return ind;
}

// Recursive [TC: O(logn),AS: O(logn)]
int lastOccRecur(int arr[], int l, int h, int x, int n)
{
    int mid = l + (h - l) / 2;
    if (arr[mid] > x)
    {
        return lastOccRecur(arr, l, mid - 1, x, n);
    }
    else if (arr[mid] < x)
    {
        return lastOccRecur(arr, mid + 1, h, x, n);
    }
    else
    {
        if (mid == n - 1 || arr[mid] != arr[mid + 1]) // Last Occurence Condition
        {
            return mid;
        }
        else // Given element found but not last occurence
        {
            return lastOccRecur(arr, mid + 1, h, x, n);
        }
    }

    return -1;
}

// Iterative [TC: O(logn),AS: O(1)]
int lastOccIter(int arr[], int n, int x)
{
    int l = 0, h = n - 1, mid = 0;

    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            if (mid == n - 1 || arr[mid] != arr[mid + 1]) // Last Occurence Condition
            {
                return mid;
            }
            else // Given element found but not last occurence
            {
                l = mid + 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5, 5, 10, 10, 10, 20}, n = 6;

    int x = 10;

    cout << lastOccNaive(arr, n, x) << endl;
    cout << lastOccRecur(arr, 0, 5, x, n) << endl;
    cout << lastOccIter(arr, n, x) << endl;
}
