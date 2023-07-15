/*
A theif follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses.
At the same time, he wants to maximize the amount he loots. Find the maximum money he can get if he strictly follows the rule.

Input: n = 6, a[] = {10,5,15,20,2,30}
Output: 60 (10+20+30=60)
*/
#include <bits/stdc++.h>
using namespace std;

// Tabulation DP
int findMaxLoot(int arr[], int n)
{
    // Base Case: Only one house to loot
    if (n == 1)
        return arr[0];

    vector<int> dp(n, 0); // table to store maximum loot
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    int maxLoot = dp[1]; // Maximum loot obtained

    for (int i = 2; i < n; i++)
    {
        // if we do not loot the current house => dp[i-1]
        // and if we loot the current house => dp[i - 2] + arr[i]
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        maxLoot = max(maxLoot, dp[i]); // Update the maximum loot
    }

    return maxLoot; // Return the maximum loot possible
}

int main()
{
    int n = 6, arr[] = {10, 5, 15, 20, 2, 30};
    cout << findMaxLoot(arr, n);
}