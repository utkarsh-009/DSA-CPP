/*
    I/P:
    O/P:
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
int leftmostNonRepeating(string s)
{
    vector<int> vis(26, -1);
    int n = s.length();
    int non_rep = 0;
    for (int i = 0; i < n; i++)
    {
        vis[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[s[i] - 'a'] == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string str = "geeksforgeeks";
    cout << "Index of leftmost non-repeating element:" << endl;
    cout << leftmostNonRepeating(str) << endl;
}
