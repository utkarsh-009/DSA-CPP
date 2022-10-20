/*
Rules :
We have to allocate n books amongst k students
0. Page allocation is done s.t. each student reads at least 1 book
1. Minimize the maximum pages allocated
2. Only contiguous page can be allocated

    I/P: arr[] = {10,20,30,40}, k = 2
    O/P: 60 [min(10 + 20 + 30, 40)]

    I/P: arr[] = {10, 5, 30, 1, 2, 5, 10, 10}, k = 3
    O/P: 30 [min(10+5, 30, 1+2+5+10+10)]
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Appraoch [TC: Exponential]
/*
We have to choose k-1 cuts out of n-1 cuts=> Total Ways = aCb (a = n-1, b = k-1)
And after finding all the combination we have to find minimum of the maximum.
*/

// To find sum of subarray
int sum(int arr[], int start, int end)
{
    int s = 0;
    for (int i = start; i <= end; i++)
    {
        s += arr[i];
    }

    return s;
}

// Recursive function to minimize the maximised allocated pages
int minPagesNaive(int arr[], int n, int k)
{
    // last cut will be the remaining array itself, as we only wanted to make k-1 cuts
    if (k == 1) // if only 1 student left => all books will be allocated to him
    {
        return sum(arr, 0, n - 1); // finding sum of all values in remaining array
    }

    if (n == 1) // if only 1 element left => there will be no further cuts
    {
        return arr[0]; // the value of last cut will be the element itself
    }

    int res = INT_MAX;
    // find max(recursively call minPage function for k-1 cuts, sum of the kth cut)
    for (int i = 0; i < n; i++)
    {
        res = min(res, max(minPagesNaive(arr, i, k - 1), sum(arr, i, n - 1)));
    }

    return res;
}
// Binary Search [TC: ,AS: ]
// Function to check how many students required when no student gets more than given no of pages
bool isFeasible(int arr[], int n, int k, int num_of_pages)
{
    int sum = 0, req = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > num_of_pages)
        {
            req++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }

    return (req <= k);
}

/*
It sets upper limit as sum and lower limit as no of maximum pages for a book (high = sum , low = mx)
Now it performs binary search to find feasible page s.t. we minimize the maximum no of pages allocated.
*/
int minPagesEff(int arr[], int n, int k)
{
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int low = mx, high = sum, res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

int main()
{
    int arr[] = {10, 20, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << minPagesEff(arr, n, k);
}
