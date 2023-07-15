/*
Given an array of coins with values, you and your opponent take turns selecting either the first or last coin from the array.
The goal is to maximize the total value of the coins you collect. You need to find the maximum possible amount of money you
can win if you go first.

Input: N = 4, A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum value as 22(7 + 15)
*/

#include <bits/stdc++.h>
using namespace std;

int memoDP(int arr[], int i, int j, vector<vector<int>> &dp)
{
    // Base case: If the start index is greater than the end index, no coins are left to select.
    if (i > j)
        return 0;

    // If the value for this subproblem is already calculated, return it.
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the maximum value by choosing either the coin at the start or end, and minimizing the opponent's move.
    dp[i][j] = max(
        arr[i] + min(memoDP(arr, i + 2, j, dp), memoDP(arr, i + 1, j - 1, dp)),
        arr[j] + min(memoDP(arr, i + 1, j - 1, dp), memoDP(arr, i, j - 2, dp)));

    return dp[i][j];
}

int main()
{
    int n = 4, arr[] = {8, 15, 3, 7};
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << memoDP(arr, 0, n - 1, dp);
}
