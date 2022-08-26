/*
    I/P: n = 12
    O/P: 2 2 3

    I/P: 13
    O/P: 13
*/

#include <bits/stdc++.h>
using namespace std;

/*
Note:
1.) Divisors always appear in pairs => 6 => (2,3) and (3,2) are same and its calculation can be avoided
2.) Number n can be written as multiplcations of powers of prime factors => 12 = 4*3 => 2^2 * 3
*/

// Efficient
void printPrimeFactors(int n)
{
    if (n <= 1)
        return;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";

            n = n / i;
        }
    }

    if (n > 1)
        cout << n << " ";

    cout << endl;
}

// Efficient Optimised (TC: 0(sqrt(n)/6))
void printPrimeFactorsEff(int n)
{
    if (n <= 1)
    {
        return;
    }

    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }

    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }

        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }

    if (n > 3)
    {
        cout << n << " ";
    }
}

int main()
{

    int n = 13;

    printPrimeFactors(n);
    printPrimeFactorsEff(n);

    return 0;
}