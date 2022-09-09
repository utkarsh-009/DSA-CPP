/*
LCS: Longest Common Subsequence: It is sub-sequence which may not be continuous but follows sequential order

I/P: s1 = "ABCDGH"
     s2 = "AEDFHR"
O/P: 3 (Common Subsequence => A, D, H)

*/

#include <iostream>
using namespace std;

// Naive [TC: O(2^n)]
int lcs(string s1, string s2, int m, int n)
{
    // Base Case
    if (m == 0 || n == 0) // if any of the string length becomes 0 => return 0
    {
        return 0;
    }

    // We find lcs by comparing ends of the strings
    if (s1[m - 1] == s2[n - 1]) // Subsequence found condition
    {
        return 1 + lcs(s1, s2, m - 1, n - 1); // Add 1 + decreasing string length from both s1 and s2 and finding lcs recursievly
    }

    // Now case when we dont find lcs, we decreasing string length from s1 and s2 independently and find their lcs
    return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1)); // returning max of two recursive function after computing them
}

int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int m = s1.length(), n = s2.length();

    cout << lcs(s1, s2, m, n);
}