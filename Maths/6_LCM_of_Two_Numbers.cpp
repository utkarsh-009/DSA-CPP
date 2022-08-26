/*
    I/P: a = 4, b = 6
    O/P: 12

    I/P: a = 7, b = 13
    O/P: 91
*/

#include <bits/stdc++.h>
using namespace std;

/*
Note: A*B = GCD(A,B)*LCM(A,B) => LCM(A,B) = A*B / GCD(A,B)
Find GCD using Euclidean Alogrithm, divide A*B by GCD to get LCM
*/

// Efficient Solution [TC: O(log(min(a,b)), AS: O(log(min(a,b))]
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