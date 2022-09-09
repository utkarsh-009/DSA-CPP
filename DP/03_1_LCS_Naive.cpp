/*
LCS: Longest Common Subsequence: It is sub-sequence which may not be continuous but follows sequential order

I/P: s1 = "ABCDGH"
     s2 = "AEDFHR"
O/P: 3 (Common Subsequence => A, D, H)

*/

#include <iostream>
using namespace std;

int lcs(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcs(s1, s2, m - 1, n - 1);
    }

    return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int m = s1.length(), n = s2.length();

    cout << lcs(s1, s2, m, n);
}