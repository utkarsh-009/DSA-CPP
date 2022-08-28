/*
    I/P: arr[] = {10,20,30,40,50,8,9}, x = 30
    O/P: 2

    I/P: arr[] = {100, 200, 400, 10, 20} x = 40
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(logn),AS: O(1)]
int searchInSortedRotatedArray(int arr[], int n, int x)
{
    int low = 0, high = n - 1, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }

        // Modified Binary Search to check whether left half is sorted or not
        else if (arr[low] < arr[mid]) // left Half Sorted
        {
            if (x >= arr[low] && x < arr[mid]) // searching in left sorted half
            {
                high = mid - 1;
            }
            else // searching in right sorted half
            {
                low = mid + 1;
            }
        }
        else // Right Half Sorted
        {
            if (x > arr[mid] && x <= arr[high]) // searching in righkt sorted half
            {
                low = mid + 1;
            }
            else // searching in left sorted half
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 8, 9}, x = 30, n = 7;

    cout << searchInSortedRotatedArray(arr, n, x);
}
