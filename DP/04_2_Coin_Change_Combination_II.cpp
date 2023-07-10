/*
Coin Change - Number of ways
Given, infinite supply of coins, each having some value. Find out the number of ways to use the coins
to sum-up to a certain required value.

Input: value = 4, numberOfCoins = 3, coins[] = {1,2,3}
Output: 4
Explanation: We need to make the change for value = 4. The denominations are {1,2,3} Change for 4 can be made:
1+1+1+1, 1+1+2, 1+3, 2+2
So, as it is evident, we can do this in 4 ways.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll memoDP(int coins[], int n, int curr_val, int idx, vector<vector<ll>> &dp)
{
    // Base case: If the current value becomes 0, there is exactly one way to make it (by not using any coins).
    if (curr_val == 0)
        return 1;

    // Base case: If we have reached the end of the coins array or the current value becomes negative,
    // it is not possible to make the desired value.
    if (idx >= n || curr_val < 0)
        return 0;

    // If the number of ways to make the current value using the current coin has already been calculated,
    // return the stored result.
    if (dp[idx][curr_val] != -1)
        return dp[idx][curr_val];

    // Recursive calls:
    // Calculate the number of ways by considering the current coin and subtracting its value from the current value.
    int c1 = memoDP(coins, n, curr_val - coins[idx], idx, dp);

    // Calculate the number of ways by not using the current coin and moving to the next coin.
    int c2 = memoDP(coins, n, curr_val, idx + 1, dp);

    // Store the result in the dp table and return the total number of ways.
    return dp[idx][curr_val] = c1 + c2;
}

ll tabDP(int coins[], int numberOfCoins, int value)
{
    // Create a vector to store the number of ways to make each value.
    vector<ll> dp(value + 1, 0);

    // Base case: It takes 1 way to make a value of 0 (by not using any coins).
    dp[0] = 1;

    /*
    // NOTE: We are using each coin to sum upto to a certain value => Distinct Way of Calculating
    Ex: coins[] = {1,2}, value = 3 => Using this technique the only possible ways calculated are (1+1+1,1+2)
    Because we are using a specific coin denomination used to get particular value. Then we use next denomination
    Hence, this ensures that the coin denomination are not repeated.
    */
    for (int ci = 0; ci < numberOfCoins; ci++)
    {
        // Iterate over the values from 1 to 'value'.
        for (int v = 1; v <= value; v++)
        {
            // Check if using the current coin would result in a valid value.
            if (v - coins[ci] >= 0)
            {
                // Update the number of ways to make the current value by adding the ways
                // to make the previous value without using the current coin.
                dp[v] += dp[v - coins[ci]];
            }
        }
    }

    // Return the number of ways to make the given value.
    return dp[value];
}

int main()
{
    int coins[] = {1, 2, 3};
    int value = 4, numberOfCoins = 3;

    // Memoization =>
    // vector<vector<ll>> dp(numberOfCoins, vector<ll>(value + 1, -1));
    // ll ans = memoDP(coins, numberOfCoins, value, 0, dp);
    // cout << ((ans >= INT_MAX) ? -1 : ans);

    // Tabulation =>
    ll ans = tabDP(coins, numberOfCoins, value);
    cout << ans;
}
