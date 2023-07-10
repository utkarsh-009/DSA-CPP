/*
Coin Change - All possible number of ways
Given, infinite supply of coins, each having some value. Find out all possible number of ways to use the coins
to sum-up to a certain required value.

Input: value = 4, numberOfCoins = 3, coins[] = {1,2,3}
Output: 7
Explanation: We need to make the change for value = 7. The denominations are {1,2,3} Change for 4 can be made:
1+1+1+1, 1+1+2, 2+1+1, 1+2+1, 1+3, 3+1, 2+2
So, as it is evident, we can do this in 7 ways.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//  [TC: ,AS:]

ll tabDP(int coins[], int numberOfCoins, int value)
{
    // Create a vector to store the number of ways to make each value.
    vector<ll> dp(value + 1, 0);

    // Base case: It takes 1 way to make a value of 0 (by not using any coins).
    dp[0] = 1;

    /*
    // NOTE: We are taking each value and finding number of ways the given coins can sum to that value => All possible ways of calculating
    Ex: coins[] = {1,2}, value = 3 => Using this technique the all possible ways calculated are (1+1+1, 1+2, 2+1)
    Because we taking a specific value are counting no of ways the coins can be added to get that particular value.
    Hence, in this manner we calculate all possible ways to get the value using coins.
    */
    for (int v = 1; v <= value; v++)
    {
        for (int ci = 0; ci < numberOfCoins; ci++)
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

    // Tabulation =>
    ll ans = tabDP(coins, numberOfCoins, value);
    cout << ans;
}
