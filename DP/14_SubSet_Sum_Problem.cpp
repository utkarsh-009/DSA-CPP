/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set
with sum equal to given sum.

Input: N = 6, arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(N*Sum), AS: O(N*Sum)]
bool solve(vector<int> &arr, int sum, int i, vector<vector<int>> &dp)
{
    if (i > arr.size() || sum < 0)
        return 0;

    if (sum == 0)
        return 1;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    return dp[i][sum] = solve(arr, sum, i + 1, dp) | solve(arr, sum - arr[i], i + 1, dp);
}

int main()
{
    int n = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    cout << solve(arr, 9, 0, dp);
}