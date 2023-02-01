/*
Two strings are anagram of each other if those two strings are permutation of each other i.e.
they should have frequency of every character equal.

    I/P: s1 = "listen", s2 = "silent"
    O/P: YES
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
bool areAnagram(string s1, string s2)
{
    vector<char> count(256);
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "abaac";
    string str2 = "aacba";
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each other";

    return 0;
}
