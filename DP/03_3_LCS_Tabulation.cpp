/*
LCS: Longest Common Subsequence: It is sub-sequence which may not be continuous but follows sequential order

I/P: s1 = "ABCDGH"
     s2 = "AEDFHR"
O/P: 3 (Common Subsequence => A, D, H)

*/

#include <iostream>
#include <vector>
using namespace std;

// Tabulation Technique  [TC: O(m*n), AS: O(m*n)]
int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); // Tabulation Array to store solutions of all subproblems

    for (int i = 0; i <= m; i++) // All zeroes in 1st column
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) // All zeroes in 1st row
    {
        dp[0][j] = 0;
    }

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
    cout << lcs(s1, s2);
}
