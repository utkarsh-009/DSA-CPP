/*
    I/P: "ABCDASDABCD"
    O/P:  0 7
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
void patSearch(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m;)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }

        if (j == m)
        {
            cout << i << " ";
        }
        i++;
    }
}

int main()
{
    string txt = "ABCDABCD";
    string pat = "ABCD";
    cout << "All index numbers where pattern found:" << endl;
    patSearch(txt, pat);
}
