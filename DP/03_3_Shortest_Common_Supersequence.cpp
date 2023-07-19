/*
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both,
X and Y as its sub-sequences.
Input: X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence would be abxycd which is of length 6 and
has both the strings as its subsequences.

Note: X and Y can have both uppercase and lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

/*
NOTE: Length of shortest common supersequence will be => len(str1)+len(str2)-lcs(str1,str2)
*/
string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // if we want to find length of Shortest Common Supersequence => return len(str1)+len(str2)-lcs(str1,str2)

    string str = "";
    // finding super sequence
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str += str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str += str1[i - 1];
            i--;
        }
        else
        {
            str += str2[j - 1];
            j--;
        }
    }

    while (i > 0)
    {
        str += str1[i - 1];
        i--;
    }

    while (j > 0)
    {
        str += str2[j - 1];
        j--;
    }

    string superSeq(str.rbegin(), str.rend());
    return superSeq;
}

int main()
{
    string s1 = "abcd", s2 = "xycd";
    cout << shortestCommonSupersequence(s1, s2) << endl;
}