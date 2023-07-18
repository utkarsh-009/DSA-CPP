/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

Input: str = "abacbc"
Output: 3
a b a c b c
0 1 2 3 4 5

{a0, b1, c3} and {a2, b4, c5} are longest repeating subsequence
NOTE: There is no common character in longest repeating subsequence
*/

#include <bits/stdc++.h>
using namespace std;

/*
- NOTE: The important condition in LRS is there should be no common character in longest repeating subsequence
Approach:
- We find longest common subsequence of string s with itself, while considering that the characters at equal
indexes are not same.
Ex: s1 = abacbc, s2 = abacbc => Perform the Longest common subsequence where s1[i]==s1[j] and i!=j.
*/

int lrs(string str)
{
    // copy string to find subsequence of string with itself
    string cpyStr = str;
    int n = str.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // valid lcs: s1[i]==s1[j] and i!=j.
            if (str[i - 1] == cpyStr[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // lcs not possible
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main()
{
    string s = "abacbc";
    cout << lrs(s);
}