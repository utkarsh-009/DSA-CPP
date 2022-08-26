/*
    I/P: a = 4
    O/P: NO

    I/P: a = 7
    O/P: YES
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(sqrt(n)), AS: O(1)]
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Efficient Optimised [Three times faster than above approach]
bool isPrimeEff(int n)
{
    if (n == 1)
    {
        return false;
    }

    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}