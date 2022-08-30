/*
    I/P: N = 10, arr[] = {2,3,4,5,6,7,8,9,10,1}
    O/P: 1

    I/P: N = 5, arr[] = {3,4,5,1,2}
    O/P: 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach: Minimum Element is only the element whose previous is greater than it in sorted rotated array

//  Recursive  [TC: O(logn),AS: O(logn)]
int minNumberRecur(int arr[], int low, int high)
{
    if (high < low) // No rotation case
    {
        return arr[0];
    }
    else if (high == low) // only 1 element present
    {
        return arr[low];
    }
    int mid = low + (high - low) / 2;
    
    if (mid < high && arr[mid] > arr[mid + 1]) // Curr > Next
    {
        return arr[mid + 1];
    }
    else if (low < mid && arr[mid - 1] > arr[mid]) // Prev > Curr
    {
        return arr[mid];
    }
    else if (arr[mid] < arr[high]) // Checking in left half
    {
        return minNumberRecur(arr, low, mid - 1);
    }
    else // Checking in right half
    {
        return minNumberRecur(arr, mid + 1, high);
    }
}

// Iterative [TC: O(logn),AS: O(1)]
int minNumberIter(int arr[], int low, int high)
{
    int ans = arr[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid < high && arr[mid] > arr[mid + 1]) // Curr > Next
        {
            ans = arr[mid + 1];
            break;
        }
        else if (mid > low && arr[mid - 1] > arr[mid]) // Prev > Curr
        {
            ans = arr[mid];
            break;
        }
        else if (arr[mid] < arr[high]) // Checking in left half
        {
            high = mid - 1;
        }
        else // Checking in right half
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
}
