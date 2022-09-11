/*
Find minimum coins required to get given sum using greedy approach
    I/P: coins[] = {10,5,2,1}, amount = 52
    O/P: 6 [10(5), 2(1)]

NOTE: Greedy Approach does not always give the optimal solution
Greedy gives output 3 but the actual output is 2 i.e 10(2)
    I/P: coins[] = {18,1,10}, amount = 20
    O/P: 3 [18(1), 1(2)]

*/

#include <bits/stdc++.h>
using namespace std;

// Greedy Approach [TC: O(nlogn), AS: O(1)]
int getMinCoins(int coins[], int n, int amount)
{
    sort(coins, coins + n, greater<int>()); // Sorting in descending order

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
        {
            int c = floor(amount / coins[i]); // Max no of coins taken of specific denomination
            res += c;                         // Total No of Coins
            amount -= c * coins[i];           // New amount required
        }

        if (amount == 0) // Required Sum is reached
        {
            break;
        }
    }
    return res;
}

int main()
{
    int coins[] = {10, 5, 2, 1}, n = 4, sum = 52;
    // int coins[] = {18, 1, 10}, n = 3, sum = 20;

    cout << getMinCoins(coins, n, sum);
}
