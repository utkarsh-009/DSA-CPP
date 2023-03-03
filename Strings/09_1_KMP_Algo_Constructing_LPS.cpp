/*
LPS: Longest Proper Prefix Suffix Array.
Ex: "abcd"
    Proper Prefix:
    "", "a", "ab", "abc"
    Suffix:
    "", "d", "cd", "bcd", "abcd"

    We have to store max length of common longest proper prefix and suffix array

I/P: str = "ababc"
O/P: lps[] = {0,0,1,2,0}

I/P: str = "aaaa"
O/P: lps[] = {0,1,2,3}

I/P: str = "abacabad"
O/P: lps[] = {0,0,1,0,1,2,3,0}
*/
#include <bits/stdc++.h>
using namespace std;

// Naive O[n^3]
int longestProperPrefixSuffix(string str, int n)
{
    for (int len = n - 1; len > 0; len--) // Starting from max possible ans
    {
        bool flag = true;
        for (int i = 0; i < len; i++) // checking if the current length is lps
        {
            if (str[i] != str[n - len + i]) // not equal
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

// Efficient [TC: O(n)]
void fillLPSEfficient(string str, int *lps)
{
    int n = str.length();
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < n)
    {
        /*
        KMP Algorithm:
        Case1 (When characters match): if len = lps[i-1] and str[i] == str[len] => lps[i] = len+1; 
        Case2 (When characters do not match): 
                if str[i] != str[len] :
                    a.) if len == 0 => lps[i] = 0
                    b.) Else, we recursively apply
                        len = lps[len-1] and compare str[i] with str[len]
        */

        // Case1
        if (len == lps[i - 1] && str[i] == str[len])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }

        // Case2
        else
        {
            // Case2a
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            // Case2b
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int main()
{
    string txt = "abacabad";
    int lps[txt.length()];
    fillLPSEfficient(txt, lps);
    for (int i = 0; i < txt.length(); i++)
    {
        cout << lps[i] << " ";
    }

    return 0;
}