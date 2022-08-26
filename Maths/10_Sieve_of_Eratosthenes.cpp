/*
Printing all the primes numbers less than or equal to given number

    I/P: n = 10
    O/P: 2 3 5 7

    I/P: n = 23
    O/P: 2 3 5 7 11 13 17 19 23
*/
#include <bits/stdc++.h>
using namespace std;

// Naive Solution [TC: O(n*sqrt(n))]
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    else if (n == 2 || n == 3)
    {
        return true;
    }

    else if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    else
    {
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
    }

    return true;
}

void printPrimes(int n)
{

    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

// Efficient Approach: Sieve of Eratosthenes [TC: O(n*log(logn)) => Term 'log(logn)' is so small that, TC: O(n)]
void seieveOfEratosthenes(int n)
{
    vector<bool> isPrimeNum(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrimeNum[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                isPrimeNum[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isPrimeNum[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{

    int n = 23;

    printPrimes(n);
    seieveOfEratosthenes(n);
}