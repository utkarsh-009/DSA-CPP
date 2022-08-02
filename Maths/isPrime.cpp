#include <bits/stdc++.h>
using namespace std;

/*
a = 4, b = 6 => 12
a = 100, b = 200 => 200
*/

// Naive
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Efficient
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