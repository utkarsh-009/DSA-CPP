/*
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:
    Insert a character at any position of the string.
    Remove any character from the string.
    Replace any character from the string with any other character.

I/P: s = "SATURDAY", t = "SUNDAY"
O/P: 3
*/

#include <bits/stdc++.h>
using namespace std;
/*
For unmatched character:
- insert operation: In insert operation, we basically
- remove operation: In remove operation, we basically remove the ith character of string s.
This means we removed the ith index => we increment i to i+1 and check (i+1)th character and jth character
- replace operation: In replace operation, we simply replace ith character of string s by jth character of string t.
As, now both ith and jth character => we increment both to i+1 and j+1 i.e. check for next characters.
*/
// [TC: O(n1*n2), AS: O(n1*n2)]
int memoDP(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    int n1 = s.length(), n2 = t.length();
    // Base case: If we have reached the end of both strings, return 0.
    if (i >= n1 && j >= n2)
        return 0;

    // Base cases: If one of the strings is empty, return the remaining length of the other string.
    if (i >= n1)
        return n2 - j;

    if (j >= n2)
        return n1 - i;

    // If the subproblem has already been solved, return the stored result.
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the current characters of both strings match, move to the next positions.
    if (s[i] == t[j])
    {
        return dp[i][j] = memoDP(s, t, i + 1, j + 1, dp);
    }
    else
    {
        // If the characters don't match, consider three possible operations: insert, remove, replace.
        int insertOp = 1 + memoDP(s, t, i, j + 1, dp);      // Insert a character into string s
        int removeOp = 1 + memoDP(s, t, i + 1, j, dp);      // Remove a character from string s
        int replaceOp = 1 + memoDP(s, t, i + 1, j + 1, dp); // Replace a character in string s with a character from string t

        // Choose the minimum cost among the three operations.
        int minOp = min(insertOp, min(removeOp, replaceOp));
        return dp[i][j] = minOp;
    }
}

// Space Optimised  [TC: O(n1*n2), AS: O(n2)]
/*
NOTE: Since each row only depends on the previous row, we can optimize the space complexity by using a 2-row DP table instead.
*/
int tabDPSpaceOptimised(string s, string t)
{
    int n1 = s.length(), n2 = t.length();
    // Create a 2D DP table with 2 rows to store the minimum edit distance values.
    vector<vector<int>> dp(2, vector<int>(n2 + 1, 0));

    // Initialize the base case for the first row.
    for (int i = 0; i <= n2; i++)
    {
        dp[0][i] = i;
    }

    // Iterate over each character in string s.
    for (int i = 1; i <= n1; i++)
    {
        // Initialize the first column value of the current row.
        dp[1][0] = i;

        // Iterate over each character in string t.
        for (int j = 1; j <= n2; j++)
        {
            // If the current characters of both strings match, no operation is needed.
            // Copy the previous diagonal value from the previous row.
            if (s[i - 1] == t[j - 1])
            {
                dp[1][j] = dp[0][j - 1];
            }
            // If the characters don't match, choose the minimum cost among three operations: insert, remove, replace.
            else
            {
                dp[1][j] = 1 + min(dp[0][j - 1], min(dp[1][j - 1], dp[0][j]));
            }
        }

        // Update the values of the previous row to the values of the current row for the next iteration.
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = dp[1][j];
        }
    }

    // Return the minimum edit distance from the last row of the DP table.
    return dp[1][n2];
}

int main()
{
    string s = "SATURDAY", t = "SUNDAY";
    int n1 = 8, n2 = 6;
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    // cout << memoDP(s, t, 0, 0, dp);

    cout << tabDPSpaceOptimised(s, t);
}