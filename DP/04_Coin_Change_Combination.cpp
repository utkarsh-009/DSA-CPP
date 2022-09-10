/*
Find total no of combination possible with given coins s.t. sum of coins in combination will be equal to given sum
    I/P: {1,2,3}, sum = 4
    O/P: 4 (1+1+1+1, 2+2, 3+1, 2+1+1)

    I/P: {2, 5, 3, 6}, sum = 10
    O/P: 5 (2+2+2+2+2, 5+5, 2+2+6 ,2+2+3+3, 2+3+5)
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Naive [TC: O(2^n), AS: O(2^n)]
int getCountRecur(int coins[], int n, int sum)
{
    // Base Case
    if (sum == 0) // The sum of coins in combination will be equal to given sum
    {
        return 1; // To not not pick any coin
    }

    if (n == 0)
    {
        return 0; // No coins left
    }

    // Case1: we dont include last coin
    int res = getCountRecur(coins, n - 1, sum); // Hence, sum is not subtracted by last coin

    // Case2: we include last coins
    if (coins[n - 1] <= sum) // Condition to include to last coin
    {
        res += getCountRecur(coins, n, sum - coins[n - 1]); // Hence, sum is subtracted by value of last coin
    }

    return res;
}

// DP Optimised Tabulation [TC: O(), AS: O()]
int getCount(int coins[], int n, int sum)
{
        
}

int main()
{

    int coins[] = {1, 2, 3}, sum = 4, n = 3;

    cout << getCountRecur(coins, n, sum);
}
