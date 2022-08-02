#include <bits/stdc++.h>
using namespace std;

/*
a = 15 => 1 3 5 15
b = 48 => 1 2 3 4 6 8 12 16 24 48
*/

// Efficient TC: O(sqrt(n))
void printDivisors(int n)
{
    int i;
    // Print all divisors from 1 to sqrt(n)
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i;
        }
    }

    // Print all divisors from sqrt(n) to n
    for (; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cout << (n / i);
        }
    }
}