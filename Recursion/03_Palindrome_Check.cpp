/*
    I/P: abbcbba
    O/P: Yes

    I/P: abcb
    O/P: No
*/

#include <bits/stdc++.h>
using namespace std;

// Start and End should be passed initially [TC: O(n),AS: O(n)]
bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    // return ((str[start] == str[end]) && isPalindrome(str, start + 1, end - 1));

    else if (str[start] == str[end])
    {
        return isPalindrome(str, start + 1, end - 1);
    }

    return false;
}

int main()
{
    string s1 = "abbcbba";
    string s2 = "abcb";

    ((isPalindrome(s1, 0, s1.length() - 1)) ? cout << "Yes" << endl : cout << "No" << endl);
    ((isPalindrome(s2, 0, s2.length() - 1)) ? cout << "Yes" << endl : cout << "No" << endl);
    return 0;
}
