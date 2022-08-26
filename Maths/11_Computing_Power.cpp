/*
x^n
    I/P: x = 2, n = 3
    O/P: 8

    I/P: x = 2, n = -2
    O/P: 0.25
*/

#include <bits/stdc++.h>
using namespace std;

/*
Efficient Approach:
    if n%2 == 0 => pow(x,n/2) * pow(x,n/2);
    else => x*pow(x,n/2)
*/

// Recursive [TC: O(logn), AS: O(logn)]
double powRecur(int x, int n)
{
    if (n == 0 || x == 1)
    {
        return 1;
    }

    double temp = powRecur(x, abs(n) / 2);
    temp *= temp;

    if (abs(n) % 2 == 0)
    {
        return ((n > 0) ? temp : 1 / temp);
    }
    else
    {
        return ((n > 0) ? temp * x : 1 / (temp * x));
    }
}

// Iterative [TC: O(logn), AS: O(1)]
double powIter(int x, int n)
{
    int pow = abs(n);
    double res = 1;

    while (pow > 0)
    {
        if (pow % 2 != 0)
        {
            res = res * x;
            pow = pow - 1;
        }
        x = x * x;
        pow = pow / 2;
    }
    return ((n > 0) ? res : 1 / res);
}

int main()
{

    int x1 = 2, n1 = 3;
    int x2 = 2, n2 = -2;

    cout << powRecur(x1, n1) << endl;
    cout << powRecur(x2, n2) << endl;
    cout << powIter(x1, n1) << endl;
    cout << powIter(x2, n2) << endl;
}