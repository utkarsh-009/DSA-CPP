/*
0 - 1 Knapsack Problem:
Maximize total value by selecting items within weight constraint.
Each item can only be selected either fully (1) or not at all (0), without any fractions.

Input: N = 3, W = 4, values[] = {1,2,3}, weight[] = {4,5,1}
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(N*W), AS: O(N*W)]
int memoDP(int W, int wt[], int val[], int n, int idx, vector<vector<int>> &dp)
{
    // Base case: If all items have been processed
    if (idx >= n)
        return 0;

    // If the current subproblem has already been solved, return the stored result
    if (dp[W][idx] != -1)
        return dp[W][idx];

    // Check if the current item's weight can be included in the knapsack capacity
    if (W - wt[idx] >= 0)
    {
        // Two choices: include the current item or exclude it
        int c1 = val[idx] + memoDP(W - wt[idx], wt, val, n, idx + 1, dp); // Include the current item
        int c2 = memoDP(W, wt, val, n, idx + 1, dp);                      // Exclude the current item

        // Choose the maximum value among the two choices
        return dp[W][idx] = max(c1, c2);
    }
    else
    {
        // If the current item's weight exceeds the knapsack capacity, exclude it
        return dp[W][idx] = memoDP(W, wt, val, n, idx + 1, dp);
    }
}

// Tabulation [TC: O(N*W), AS: O(N*W)]
int tabDP(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // index i-> 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // weights w-> 0 to W
        for (int w = 0; w <= W; w++)
        {
            // if it is weight possible to put weight in knapsack => we have two choices i.e. either we put in or we not
            if (w - wt[i] >= 0)
            {
                int c1 = val[i] + dp[i][w - wt[i]];
                int c2 = dp[i][w];
                dp[i + 1][w] = max(c1, c2);
            }
            // else if it is not weight possible to put weight in knapsack => we simply move to next weight
            else
            {
                dp[i + 1][w] = dp[i][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int n = 3, w = 4;
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};

    cout << tabDP(w, wt, val, n);
}