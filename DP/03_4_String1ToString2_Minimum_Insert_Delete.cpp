/*
The minimum number of steps required to convert string1 to string2 using delete and insert operations.
    Input: string1 = "sea", string2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Input: string1 = "leetcode", string2 = "etco"
    Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
int lcs(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(501, vector<int>(501, -1));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int minInsertDelOperations(string word1, string word2)
{
    int m = word1.length(), n = word2.length();

    int l = lcs(word1, word2, m, n);
    int del = m - l, insert = n - l;

    return (del + insert);
}

int main()
{

    string word1 = "sea", word2 = "eat";

    cout << minDistance(word1, word2);
}
