/*
Finding kth smallest element in unsorted array
    I/P: [10,5,30,12], k = 2
    O/P: 10
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(nlogn), AS: O(1)]
int kthSmallestNaive(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

// Efficient, Works Better In Average Case [TCavg: O(nlogn), AS: O(n)]
// NOTE: In worst case, TC can go upto O(n*n)
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low - 1, j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

// We have to choose kth smallest element as pivot => After partitioning the kth smallest element will be at the (k-1)th index
int kthSmallest(int arr[], int n, int k)
{
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int p = partition(arr, l, h); // make partition around new subarray

        if (p == k - 1) // partition is done arround the kth element
        {
            return arr[p];
        }

        else if (p > k - 1)
        {
            h = p - 1;
        }
        else // p < k - 1
        {
            l = p + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10, 5, 30, 12}, k = 2, n = 4;

    cout << kthSmallest(arr, n, k);
}