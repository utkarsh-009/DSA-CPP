/*
    I/P: arr[] = {2,3,-8,7,-1,2,3}
    O/P: 11

    I/P: arr[] = {-6,-1,-8}
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

// Divide And Conquer Algorithm [TC: O(nlogn), AS: O(1)]
/*
    Intution:
    GOAL: We find max sum if Maximum Subarray Sum is present in Left SubArray, Mid Subarray and Right Subarray

    LEFT/RIGHT SUBARRAY: This will be calculated recursievly by giving the appropriate array pointer and size as n/2

    MID SUBARRAY: Also there might be a case when Maximum Subarray is present in between of Left and Right i.e.
    It will consist of element of some portion of Left and some portion of right subarray.
*/

int maxSubarraySumDivAndCon(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int m = n / 2;

    // Finding left_MSS and right_MSS
    int left_MSS = maxSubarraySumDivAndCon(arr, m);          // Recursievly finding the left maximum sum subarray
    int right_MSS = maxSubarraySumDivAndCon(arr + m, n - m); // Recursievly finding the right maximum sum subarray

    // Finding mid_MSS
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

    for (int i = m - 1; i >= 0; i--)
    {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;
    for (int i = m; i < n; i++)
    {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    int mid_MSS = left_sum + right_sum;

    return max(left_MSS, max(mid_MSS, right_MSS));
}

int main()
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3}, n = 7;

    cout << maxSubarraySumDivAndCon(arr, n);
}
