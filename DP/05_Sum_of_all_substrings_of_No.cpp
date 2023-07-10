/*
Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, print it modulo 10^9+7.

Input:
S = 1234
Output: 1670
Explanation: Sum = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234 = 1670

// Dry Run for Efficient Approach: dp[i] = (i+1)*(curr_char) + dp[i-1]*10
1234
1 => "1" = 1
12 => "12" + "2" => 14 ((1+1)*2 + 1*10)
123 => "123" + "23" + "3" =>  149 ((2+1)*3 + 14*10)
1234 => "1234" + "234" + "34" + "4" => 1506 ((3+1)*4 + 149*10)

1+14+149+1506 => 1670
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Naive: [TC: O(N*N*N), AS: O(1)]
long long sumSubstringsNaive(string s)
{
    ll sum = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            string temp = s.substr(i, len);
            sum += stoi(temp);
        }
    }

    return sum;
}

// Efficient: [TC: O(N), AS: O(N)]
// Function to calculate the sum of all possible substrings of a given string using a tabulation approach.
long long sumSubstringsTab(string s)
{
    int n = s.length();

    // Base case: If the string is empty, return 0.
    if (n == 0)
    {
        return 0;
    }

    vector<ll> dp(n);   // DP table to store the values of substrings.
    dp[0] = s[0] - '0'; // Initialize the first element of the DP table.
    ll ans = dp[0];     // Variable to store the overall sum of substrings.

    ll mod = 1e9 + 7; // Modulo value to avoid overflow.

    // Iterate over each character in the string starting from the second character.
    for (int i = 1; i < n; i++)
    {
        ll curr_char = s[i] - '0'; // Convert the current character to its integer value.

        /*
        Derived Formula Through Observation: dp[i] = (i+1)*curr_char + dp[i-1]*10
        Here, dp[i] refers to sum of all substring that are formed from string with index range as [0 to i], [1 to i],..,[i-1 to i]
        */
        // Calculate the value of the current substring based on the previous substring value.
        dp[i] = ((i + 1) * curr_char + dp[i - 1] * 10) % mod;

        // Add the value of the current substring to the overall sum.
        ans = (ans + dp[i]) % mod;
    }

    // Return the final sum of all substrings.
    return ans;
}

int main()
{
    string s = "1234";
    cout << sumSubstringsTab(s);
}