/*
LCS: Longest Common Subsequence: It is sub-sequence which may not be continuous but follows sequential order

I/P: s1 = "ABCDGH"
     s2 = "AEDFHR"
O/P: 3 (Common Subsequence => A, D, H)

*/

#include <iostream>
#include <vector>
using namespace std;

string s1 = "ABCDGH", s2 = "AEDFHR";
int m = s1.length(), n = s2.length();

vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1)); // Global Memorization Array to store solutions of subproblem required by main problem

// Memorisation Technique  [TC: O(m*n)]
int lcs(string s1, string s2, int m, int n)
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
        return 1 + lcs(s1, s2, m - 1, n - 1);
    }

    return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main()
{
    cout << lcs(s1, s2, m, n);
}