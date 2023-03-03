#include <bits/stdc++.h>
using namespace std;

void fillLPS(string s, int *lps)
{
    int n = s.length(), len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < n)
    {
        if (str[i] == str[len])
        {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int main()
{
}
