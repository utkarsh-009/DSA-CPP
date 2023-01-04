/*
    I/P: arr[] = {5,-2,3,4}
    O/P: 12 (5+3+4)

    I/P: arr[] = {2,3,-4}
    O/P: 5
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int maxNormalSubarraySum(int arr[], int n)
{

    int max_sum = INT_MIN, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;
}

int maxSubarraySum(int arr[], int n)
{
    int max_normal = maxNormalSubarraySum(arr, n); // calculating maximum subarray sum using kadane's algorithm

    // it means all elements are less than 0 which implies max normal will be equal to the smallest negative number
    if (max_normal < 0)
    {
        return max_normal;
    }

    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i]; // Total Array Sum
        arr[i] = -arr[i];  // Inversion of array
    }

    // After inverting array maxNormalSubarraySum(arr, n) will give minimum subarray sum
    int max_circular = arr_sum + maxNormalSubarraySum(arr, n); // Instead of subtracting, we will add minimum subarray sum as array is inverted

    return max(max_normal, max_circular);
}

int main()
{
    int arr[] = {5, -2, 3, 4}, n = 4;

    cout << maxSubarraySum(arr, n);
}
