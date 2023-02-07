/*
LPS: Longest Proper Prefix Suffix Array.
Ex: "abcd"
    Proper Prefix:
    "", "a", "ab", "abc"
    Suffix:
    "", "d", "cd", "bcd", "abcd"

I/P: str = "ababc"
O/P: lps[] = {0,0,1,2,0}

I/P: str = "aaaa"
O/P: lps[] = {0,1,2,3}
*/
#include <bits/stdc++.h>
using namespace std;

// Naive O[n^3]
int longestProperPrefixSuffix(string str, int n)
{
    for (int len = n - 1; len > 0; len--) // Starting from max possible ans
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[n - len + i]) // not
            {
                flag = false;
                break;
            }
        }

        // return ans
        if (flag)
            return len;
    }

    return 0;
}

void fillLPS(string str, int lps[])
{
    for (int i = 0; i < str.length(); i++)
    {
        lps[i] = longestProperPrefixSuffix(str, i + 1);
    }
}

int main()
{
    string txt = "abacabad";
    int lps[txt.length()];
    fillLPS(txt, lps);
    for (int i = 0; i < txt.length(); i++)
    {
        cout << lps[i] << " ";
    }

    return 0;
}