/*
Find the minimum number of coins to make the change for value using the coins of given denominations.

Input: value = 5, numberOfCoins = 3, coins[] = {3,6,3}
Output: Not Possible
Explanation:We need to make the change for value = 5, The denominations are {3,6,3}
It is certain that we cannot make 5 using any of these coins.

Input: value = 10, numberOfCoins = 4, coins[] = {2 5 3 6}
Output: 2
Explanation:We need to make the change for value = 10 The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So minimum coins are 2.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll memoDP(int coins[], int n, int curr_val, int idx, vector<vector<ll>> &dp)
{
    // Base case: If the current value is 0, no more coins are needed.
    if (curr_val == 0)
        return 0;

    // Base case: If the current value becomes negative or we have reached the end of coins array,
    // it is not possible to make the desired value.
    if (curr_val < 0 || idx >= n)
        return INT_MAX;

    // If the value has already been calculated, return the stored result.
    if (dp[idx][curr_val] != -1)
        return dp[idx][curr_val];

    // Recursive calls:
    // Try using the current coin and subtract its value from the current value.
    ll c1 = 1 + memoDP(coins, n, curr_val - coins[idx], idx, dp);

    // Move to the next coin without using the current coin.
    ll c2 = memoDP(coins, n, curr_val, idx + 1, dp);

    // Store the minimum number of coins required to make the current value using the current coin.
    return dp[idx][curr_val] = min(c1, c2);
}

ll tabDP(int coins[], int numberOfCoins, int value)
{
    // Create a vector to store the minimum number of coins required to make each value.
    vector<ll> dp(value + 1, INT_MAX);

    // Base case: It takes 0 coins to make a value of 0.
    dp[0] = 0;

    // NOTE: for each value, we need to find minimum no of coins required to make that value
    for (ll v = 1; v <= value; v++)
    {
        // Consider each coin to determine the minimum number of coins required for the current value.
        for (int ci = 0; ci < numberOfCoins; ci++)
        {
            // Check if using the current coin would result in a valid value.
            if (v - coins[ci] >= 0)
            {
                // Check if the minimum number of coins required for the previous value is not 'INT_MAX'.
                if (dp[v - coins[ci]] != INT_MAX)
                {
                    // Update the minimum number of coins required for the current value.
                    dp[v] = min(dp[v], dp[v - coins[ci]] + 1);
                }
            }
        }
    }

    // Return the result. If it is 'INT_MAX', it means it is not possible to make the given value.
    return dp[value] == INT_MAX ? -1 : dp[value];
}

int main()
{
    int coins[] = {2, 5, 3, 6};
    int value = 10, numberOfCoins = 4;

    // Memoization =>
    // vector<vector<ll>> dp(numberOfCoins, vector<ll>(value + 1, -1));
    // ll ans = memoDP(coins, numberOfCoins, value, 0, dp);
    // cout << ((ans >= INT_MAX) ? -1 : ans);

    // Tabulation =>
    ll ans = tabDP(coins, numberOfCoins, value);
    cout << ans;
}