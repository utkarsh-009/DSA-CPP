/*
LCS: Longest Common Subsequence: It is sub-sequence which may not be continuous but follows sequential order

I/P: s1 = "ABCDGH"
     s2 = "AEDFHR"
O/P: 3 (Common Subsequence => A, D, H)

*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(2^n)]
int lcsNaive(string s1, string s2, int m, int n)
{
    // Base Case
    if (m == 0 || n == 0) // if any of the string length becomes 0 => return 0
    {
        return 0;
    }

    // We find lcs by comparing ends of the strings
    if (s1[m - 1] == s2[n - 1]) // Subsequence found condition
    {
        return 1 + lcsNaive(s1, s2, m - 1, n - 1); // Add 1 + decreasing string length from both s1 and s2 and finding lcs recursievly
    }

    // Now case when we dont find lcs, we decreasing string length from s1 and s2 independently and find their lcs
    return max(lcsNaive(s1, s2, m - 1, n), lcsNaive(s1, s2, m, n - 1)); // returning max of two recursive function after computing them
}

// Memorisation Technique  [TC: O(m*n)]
int lcsMemo(string s1, string s2, int m, int n, vector<vector<int>> &memo)
{
    // DP Optimisation Step
    if (memo[m][n] != -1) // If memo[m][n] != -1 => solution already computed in some recursive call
    {
        return memo[m][n];
    }

    // Base Case
    if (m == 0 || n == 0) // if any of the string length becomes 0 => return 0
    {
        return 0;
    }

    // We find lcs by comparing ends of the strings
    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcsMemo(s1, s2, m - 1, n - 1, memo);
    }

    return max(lcsMemo(s1, s2, m - 1, n, memo), lcsMemo(s1, s2, m, n - 1, memo));
}

// Tabulation Technique  [TC: O(m*n), AS: O(m*n)]
int lcsTab(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Tabulation Array to store solutions of all subproblems

    for (int i = 0; i <= m; i++) // All zeroes in 1st column
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++) // All zeroes in 1st row
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // MATCHING Condition: dp[i][j] = 1 + dp[i - 1][j - 1]
            if (s1[i - 1] == s2[j - 1]) // Subsequence found
            {
                // dp[i-1][j-1] stores lcs until now
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Store the new lcs in dp[i][j] by adding 1 to dp[i-1][j-1]
            }

            // NOT MATCHING Condition => dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
            else // No subsequence found
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Store the new lcs in dp[i][j] by finding max of dp[i-1][j] and dp[i][j-1]
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int m = s1.length(), n = s2.length();

    // vector<vector<int>> memo(m, vector<int>(n, -1));
    cout << lcsTab(s1, s2);
}