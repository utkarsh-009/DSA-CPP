/*
    I/P: {5, 5, 10, 10, 10, 20}, n = 10
    O/P: 2

    I/P: {5, 10, 10, 10, 20}, n = 40
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n), AS: O(1)]
int firstOccNaive(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

// NOTE: Array should be sorted for Binary Search

// Binary Recursive Solution [TC: O(logn), AS: O(logn)]
int firstOccRecur(int arr[], int l, int h, int x)
{
    if (l > h)
    {
        return -1;
    }

    int mid = l + (h - l) / 2;
    if (arr[mid] > x)
    {
        return firstOccRecur(arr, l, mid - 1, x);
    }

    else if (arr[mid] < x)
    {
        return firstOccRecur(arr, mid + 1, h, x);
    }

    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid]) // First Occurence Condition
        {
            return mid;
        }
        else // Given element found but not first occurence
        {
            return firstOccRecur(arr, l, mid - 1, x);
        }
    }

    return -1;
}
// Binary Iterative Solution [TC: O(logn), AS: O(1)]
int firstOccIter(int arr[], int n, int x)
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
            if (mid == 0 || arr[mid - 1] != arr[mid]) // First Occurence Condition
            {
                return mid;
            }
            else // Given element found but not first occurence
            {
                h = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {5, 5, 10, 10, 10, 20}, n = 6;
    int x = 10;

    cout << firstOccNaive(arr, n, x) << endl;
    cout << firstOccRecur(arr, 0, n - 1, x) << endl;
    cout << firstOccIter(arr, n, x) << endl;
    return 0;
}
