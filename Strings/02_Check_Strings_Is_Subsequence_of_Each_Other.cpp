/*
    I/P: s1 = "ABCD"
         s2 = "AD"
    O/P: True

    I/P: s1 = "ABCDE"
         s2 = "AED"
    O/P: False
*/

#include <bits/stdc++.h>
using namespace std;

// Iterative [TC: O(n), AS: O(1)]
// Checking s2 is subsequence of s1
bool isSubSeqIter(string s1, string s2, int n, int m)
{
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
        }
    }

    return (j == m);
}

// Recursive [TC: O(n), AS: O(n)]
bool isSubSeqRecur(string s1, string s2, int n, int m)
{
    if (m == 0)
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return isSubSeqRecur(s1, s2, n - 1, m - 1);
    }
    else
    {
        return isSubSeqRecur(s1, s2, n - 1, m);
    }
}

int main()
{
    string s1, s2;
    s1 = "ABCD", s2 = "BD";
    int n = s1.length(), m = s2.length();

    cout << boolalpha << isSubSeqRecur(s1, s2, n, m) << endl;
    cout << boolalpha << isSubSeqIter(s1, s2, n, m) << endl;
}
