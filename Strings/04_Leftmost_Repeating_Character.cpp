/*
The leftmost repeating character is the character which is the first character that repeats itself in the string.
    I/P:
    O/P:
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(n), AS: O(n)]
int leftmostRepeating(string &s)
{
    vector<bool> visi(256, false);
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (visi[s[i]])
        {
            res = i;
        }
        else
        {
            visi[s[i]] = true;
        }
    }

    return res;
}

int main()
{
    string str = "tgeeksforgeeks";
    cout << "Index of leftmost repeating character:" << endl;
    cout << leftmostRepeating(str) << endl;

    return 0;
}
