/*
Find nCr for given n and r.

Input: n = 4, r = 2
Output: 6
*/

#include <bits/stdc++.h>
using namespace std;

// IMP FORMULA = (n-1)C(r-1) + (n-1)Cr = nCr
// [TC: O(n*r), AS: O(n*n)]
int nCrMod(int n, int r)
{
    // Invalid case
    if (r > n)
        return 0;

    int mod = 1e9 + 7;
    int dp[n + 1][n + 1];
    dp[0][0] = 0; // 0C0 = 0

    // nC0 => 1 && nCn => 1
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][i] = 1;
    }

    // IMP FORMULA = (n-1)C(r-1) + (n-1)Cr = nCr
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= min(i, r); j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }

    return dp[n][r] % mod;
}

// NOTE: the dp[i][j] value only depends upon last row, hence we can optimise the space into O(n)

int main()
{
    int n = 4, r = 2;
    cout << nCrMod(n, r);
}