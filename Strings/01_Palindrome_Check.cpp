/*
    I/P: abcba
    O/P: YES

    I/P: aaba
    O/P: NO

*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
bool isPalindrome(string s)
{
    int low = 0, high = s.length() - 1;
    while (low < high)
    {
        if (s[low] != s[high])
        {
            return false;
        }
        low++;
        high--;
    }

    return true;
}

int main()
{
    string s = "abcba";
    cout << isPalindrome(s);
}
