/*
    I/P: 7345
    O/P: 4

    I/P: 0
    O/P: 1
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive [TC: O(No of Digits), AS: O(No of Digits)]
int countDigits(long n)
{
    if (n == 0)
    {
        return 0;
    }

    return 1 + countDigits(n / 10);
}

// Iterative: [TC: O(No of Digits), AS: O(1)]
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

// Logarithmic [TC: O(1), AS: O(1)]
int countDigits(long n)
{
    return floor(log10(n)) + 1;
}
