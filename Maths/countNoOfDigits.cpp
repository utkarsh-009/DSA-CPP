#include <bits/stdc++.h>
using namespace std;

// Iterative
int countDigits(long n)
{
    int cnt = 0;
    while (n != 0)
    {
        n = n / 10;
        cnt++;
    }
    return cnt;
}

// Recursive
int countDigits(long n)
{
    if (n == 0)
    {
        return 0;
    }

    return 1 + countDigits(n / 10);
}

// Logarithmic
int countDigits(long n)
{
    return floor(log10(n)) + 1;
}
