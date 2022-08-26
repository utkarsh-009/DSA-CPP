/*
    I/P: s = "AB"
    O/P: "" "A" "B" "AB"

*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(2^n),AS: O(2^n)]
void printSubsets(string &str, string curr, int index)
{
    //
    if (index == str.length())
    {
        cout << curr << endl;
        return;
    }

    // In recursive binary tree: we either take or ignore the character
    printSubsets(str, curr, index + 1);              // character ignored
    printSubsets(str, curr + str[index], index + 1); // character added to curr
}

int main()
{
    string str = "ABC";
    // In final recursive call, we get: "" "C" "B" "BC" "A" "AC" "AB" "ABC"
    printSubsets(str, "", 0);

    return 0;
}
