/*
    I/P: 5
    O/P: 120

    I/P: 0
    O/P: 1
*/

#include <bits/stdc++.h>
using namespace std;

// Iterative (AS: O(1), TC: O(n))
long long fact(long long n)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }

    return ans;
}

// Recursive (Note: extra recursion call overhead, AS: O(n), TC: O(n) => Iterative Solution Better)
long long fact(long long n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}