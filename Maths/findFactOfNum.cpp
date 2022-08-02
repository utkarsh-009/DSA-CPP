#include <bits/stdc++.h>
using namespace std;

/*
n = 5 => 120
n = 0 => 1
*/

// Iterative (AS: O(1), TC: O(n))
int fact(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }

    return ans;
}

// Recursive (Note: extra recursion call overhead, AS: O(n), TC: O(n) => Iterative Solution Better)
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}