#include <bits/stdc++.h>
using namespace std;

/*
a = 4, b = 6 => 12
a = 100, b = 200 => 200
*/
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}