/*
    I/P: {5, 10, 20, 15, 7}
    O/P: 20

    I/P: {10, 20, 15, 5, 23, 90, 6}
    O/P: 20 OR 90
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(logn),AS: O(1)]
int getPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) // Peak element condition
        {
            return mid;
        }
        else if (mid > 0 && arr[mid - 1] >= arr[mid]) // if there exist element before mid and arr[mid - 1] >= arr[mid] => Peak element can exist in left half
        {
            high = mid - 1; // Checking peak element is left half
        }
        else // Peak element can exist in right half
        {
            low = mid + 1; // Checking peak element is right half
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 15, 5, 23, 90, 6}, n = 7;

    cout << getPeak(arr, n);

    return 0;
}
