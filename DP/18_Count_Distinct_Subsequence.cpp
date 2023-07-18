/*
Given a string, find the count of distinct subsequences of it.
Input  : str = "gfg"
Output : 7
The seven distinct subsequences are "", "g", "f","gf", "fg", "gg" and "gfg"

Input  : str = "ggg"
Output : 4
The four distinct subsequences are "", "g", "gg" and "ggg"
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(2^n), AS: O(2^n)]
unordered_set<string> st;
void subseqRecurNaive(string s, string temp, int i)
{
    if (i >= s.length())
    {
        st.insert(temp);
        return;
    }

    // Consider the character in subseq
    temp.push_back(s[i]);
    subseqRecurNaive(s, temp, i + 1);
    temp.pop_back();

    // Dont consider the character in subseq
    subseqRecurNaive(s, temp, i + 1);
}

// DP tabulation
/*
NOTE: The count is subsequence in a string of size 'n' => nC0 + nC1 + nC2 + … nCn = 2^n
Ex:
C1: Non repeating characters in string
"abc" => "","a","b","c","ab","bc","ac","abc"
dp[i] => dp[i-1]*2

C2: Repeating characters in string
But this formula cannot be generalised for counting distinct subsequences as strings like "aba"
contains repeated character, which leads to repeated count subsequences.
"aba" => "","a","b","a","ab","ba","aa","aba" (Repeating subsequence: "a")
      => "","a","b","ab","ba","aa","aba"   (Distinct Subsequence)
dp[i] => dp[i-1]*2 - dp[lastOcc-1]

NOTE:
- If current character is repeating and gets its lastOcc index using map.In this case, we need to avoid
overcounting the subsequences that include this repeating character multiple times.
- So, we subtract the number of subsequences formed by including this character at its last occurrence
index (lastOcc).
- The reason for subtracting dp[lastOcc - 1] is that we need to exclude all subsequences formed by
including this character before its last occurrence, as they will be counted twice if we just double dp[i - 1].
*/
// Function to calculate the number of distinct subsequences that can be formed from the given string s using tabulation dynamic programming.
int tabDP(string s)
{
    int n = s.length();

    // dp[i] stores the number of distinct subsequences that can be formed after including the i-th character.
    vector<int> dp(n + 1, 0); // We have n+1 size as the empty string is also considered a subsequence.
    dp[0] = 1;                // There is one subsequence with an empty string.

    // To store the last occurrence index of each character.
    unordered_map<char, int> mp;

    for (int i = 1; i <= n; i++)
    {
        char curr_char = s[i - 1];

        if (mp.find(curr_char) != mp.end())
        {
            int lastOcc = mp[curr_char];
            // When the current character is repeating, we use the formula to calculate the distinct subsequences.
            dp[i] = 2 * dp[i - 1] - dp[lastOcc - 1];
        }
        else
        {
            // When the current character is not repeating, we can simply double the number of distinct subsequences.
            dp[i] = 2 * dp[i - 1];
        }

        // Update the last occurrence index of the current character in the map.
        mp[curr_char] = i;
    }

    // Return the number of distinct subsequences that can be formed after including all characters.
    return dp[n];
}

int main()
{
    string s = "aba";

    // NAIVE
    // subseqRecurNaive(s, "", 0);
    // cout << st.size();

    // DP BASED APPROACH
    cout << tabDP(s);
}