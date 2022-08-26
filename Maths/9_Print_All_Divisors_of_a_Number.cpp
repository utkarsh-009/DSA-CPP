/*
    I/P: n = 15
    O/P: 1 3 5 15

    I/P: 48
    O/P: 1 2 3 4 6 8 12 16 24 48
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(sqrt(n))] (Prints Divisiors in Unsorted Order)
void printDivisors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i) // To avoid printing number forming perfect squares twice [ex: avoiding no 5 to print twice when n = 25]
            {
                cout << n / i << " ";
            }
        }
    }
}

// Efficient [TC: O(sqrt(n))]: (Prints Divisiors in Sorted Order)
void printDivisorsEff(int n)
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