/*
You are given N identical eggs and a building with K floors. You need to find the floor f, where 0 <= f <= K, such that dropping an egg from any floor above f will cause it to break, and dropping it from or below f will not break it.
The following rules apply:
- An egg that survives a fall can be reused.
- A broken egg cannot be used again.
- The effect of a fall is the same for all eggs.
- If an egg doesn't break at a certain floor, it will not break at any floor below.
- If an egg breaks at a certain floor, it will break at any floor above.

You need to determine the minimum number of moves required to find the value of critical f.

Input: N = 1, K = 2
Output: 2
Explanation:
1. Drop the egg from floor 1. If it
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
*/
#include <bits/stdc++.h>
using namespace std;

/*
Intution: The floor 'f' which will give minimum number of moves required to find the value of critical floor
- We will throw egg from floor 'f' where the worst case attempts will be the minimum compared to other floors
- In simple terms, the floor 'f' will give no of moves i.e. best of worst cases which will be our answer.
*/
// [TC: O(E*F*F), AS: O(E*F)]
int eggDrop(int n, int k)
{
    // NOTE: n => no of eggs
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    // for 0 eggs => Infinite attempts reqd
    for (int i = 0; i <= k; i++)
        dp[0][i] = INT_MAX;

    // for 0 floors => 0 attempts required
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int e = 1; e <= n; e++)
    {
        for (int f = 1; f <= k; f++)
        {
            if (e == 1) // if only 1 egg => no of attempts will be equal to no of floors
            {
                dp[e][f] = f;
            }
            else if (f == 1) // if only 1 floor => only 1 attemp require
            {
                dp[e][f] = 1;
            }
            else
            {
                int mini = INT_MAX;
                for (int ci = 0, cj = f - 1; cj >= 0; cj--, ci++)
                {
                    int val1 = dp[e][cj];      // egg survives
                    int val2 = dp[e - 1][ci];  // egg breaks
                    int val = max(val1, val2); // worst case taken into consideration
                    mini = min(mini, val);     // best of worst case taken into consideration
                }
                dp[e][f] = 1 + mini;
            }
        }
    }

    return dp[n][k];
}

int main()
{
    int e = 1, f = 2;
    cout << eggDrop(e, f);
}