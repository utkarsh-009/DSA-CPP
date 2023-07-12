/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element.
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Input: N = 11, a[] = {1,3,5,8,9,2,6,7,6,8,9}
Output: 3
Explanation: First jump from 1st element, and we jump to 2nd element with value 3.
Now, from here we jump to 5h element with value 9. and from here we will jump to last.
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(n*n)]
int minimumJumpsNaive(int arr[], int n)
{
    if (n == 1)
    {
        return 0; // If there is only one element in the array, no jumps are needed
    }
    if (arr[0] == 0)
    {
        return -1; // If the first element is 0, it is not possible to make any jumps
    }

    vector<int> dp(n, INT_MAX); // dp[i] will store the minimum number of jumps required to reach index i
    dp[0] = 0;                  // Number of jumps required to reach the first index is 0

    for (int i = 0; i < n; i++)
    {
        int jumps = arr[i]; // Get the maximum number of jumps from the current index
        for (int j = i + 1; j <= min(i + jumps, n - 1); j++)
        {
            // Iterate from i+1 to min(i+jumps, n-1) as we can only jump up to the maximum reachable index
            dp[j] = min(dp[i] + 1, dp[j]); // Update the minimum number of jumps required for index j
        }
    }

    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1]; // Return the minimum number of jumps required to reach the last index
}

// Efficient: Tabulation Space Optimised [TC: O(n)]
int minimumJumpsEff(int arr[], int n)
{
    // If there is only one element in the array, no jumps are needed.
    if (n == 1)
        return 0;

    // If the first element is 0, it is not possible to reach the end.
    if (arr[0] == 0)
        return -1;

    int maxReach = 0;  // The farthest index that can be reached from the current position.
    int min_jumps = 0; // The minimum number of jumps needed to reach the end.
    int curr = 0;      // The current index.

    for (int i = 0; i < n; i++)
    {
        // Update the maxReach if the current element plus its index is greater.
        maxReach = max(maxReach, arr[i] + i);

        // If the maxReach is greater than or equal to the last index => it means we have reached the end using minimum jumps.
        if (maxReach >= n - 1)
            return min_jumps + 1;

        // It means that we have reached a position where we cannot proceed further,
        // i.e. it is impossible to reach to the last index.
        if (i >= maxReach)
            return -1;

        // If the current index is equal to the maxReach => we have exhausted the jumps available from the current position.
        // We move to the farthest index we can reach and increment the jumps count.
        if (i == curr)
        {
            curr = maxReach;
            min_jumps++;
        }
    }

    // If we are unable to reach the end.
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}, n = 11;
    cout << minimumJumpsEff(arr, n);
}