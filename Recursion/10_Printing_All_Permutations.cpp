/*
    I/P: "abc"
    O/P: abc acb bac bca cab cba

    I/P: "ab"
    O/P: ab ba
*/

#include <bits/stdc++.h>
using namespace std;
 
//  [TC: O((time to print one permutaion)*(no of permutations)) => O(n * n!), AS: O(r-l)]
void printAllPerm(string &s, int l, int r)
{
    if (l == r)
    {
        cout << s << " ";
        return;
    }

    // Backtracking Approach
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        printAllPerm(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main()
{
    string s = "abc";
    int n = s.length();

    printAllPerm(s, 0, n - 1);
    return 0;
}
