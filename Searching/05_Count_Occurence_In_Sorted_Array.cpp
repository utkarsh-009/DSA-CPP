/*
    I/P: {5, 5, 10, 10, 10, 20}, n = 10
    O/P: 3

    I/P: {5, 10, 10, 10, 20}, n = 40
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

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

// Iterative [TC: O(logn) ,AS: O(1)]
int countOcc(int arr[], int n, int x)
{
    int first = firstOccIter(arr, n, x);
    if (first == -1)
    {
        return 0;
    }
    else
    {
        return lastOccIter(arr, n, x) - first + 1;
    }
}

int main()
{

    int arr[] = {5, 5, 10, 10, 10, 20}, n = 6;

    int x = 10;

    cout << countOcc(arr, n, x) << endl;
}
