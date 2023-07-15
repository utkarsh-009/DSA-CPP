/*
Given an integer. Find how many structurally unique binary search trees are there that stores the values
from 1 to that integer (inclusive).

Input: N = 3, Output: 5
Explanation: for N = 3, there are 5 possible BSTs
  1           3     3       2     1
    \        /     /      /  \     \
     3      2     1      1    3     2
    /      /       \                 \
   2      1         2                 3
*/

#include <bits/stdc++.h>
using namespace std;

/*
Recursive Formula: res(n) = res(0)*res(n-1) + res(1)*res(n-2)+res(2)*res(n-3)+... +res(n-1)*res(0)

IMP NOTE:
- res(0)*res(n-1) => 0 keys in LHS, 1 key as Root, n-1 keys in RHS
- This same formula can be used to calculation of CATALAN NUMBER
*/
int tabDP(int N)
{
    // Create a vector to store the number of unique BSTs for each number of keys.
    vector<int> dp(N + 1, 0);

    // Base case: There is only one unique BST with no keys.
    dp[0] = 1;

    // Calculate the number of unique BSTs for each total number of keys.
    for (int totalKeys = 1; totalKeys <= N; totalKeys++)
    {
        // Iterate over the possible number of nodes in the left subtree.
        for (int nodesInLhs = 0; nodesInLhs < totalKeys; nodesInLhs++)
        {
            // Calculate the number of unique BSTs by multiplying the number of unique BSTs in the left and right subtrees.
            dp[totalKeys] += (dp[nodesInLhs] * dp[totalKeys - nodesInLhs - 1]);
        }
    }

    // Return the number of unique BSTs with N nodes.
    return dp[N];
}

int main()
{
    int n = 3;
    cout << tabDP(n);
}