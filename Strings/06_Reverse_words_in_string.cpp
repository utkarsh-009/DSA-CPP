/*
    I/P:
    O/P:
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(n*(size of longest word)), AS: O(1)]
// Intution: reverse words individually and then reverse the compete string at last.
void reverse(string &s, int low, int high)
{
    while (low < high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}

void revString(string &s, int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (s[end] == ' ')
        {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    }

    reverse(s, start, n - 1);
    reverse(s, 0, n - 1);
}

int main()
{
    string s = "Welcome to Gfg";
    int n = s.length();
    cout << "After reversing words in the string:" << endl;
    revString(s, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
}
