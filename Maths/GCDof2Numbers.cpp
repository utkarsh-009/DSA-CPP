#include <bits/stdc++.h>
using namespace std;

/*
a = 4, b = 6 => 2
a = 100, b = 200 => 100

NOTE: GCD or HCF
This question can interpreted as a triangle of 4*6 size units,
then the largest size of square that can fill the rectangle completely will be square of size 2
*/

// Naive , TC: O(min(a,b))
int gcd(int a, int b)
{
    int ans = 0;
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans = i;
            break;
        }
    }

    return ans;
}

/*

gcd(a,b) = gcd(a-b, a)
Proof:
Let 'g' be GCD of 'a' and 'b' => a = gx & b = gy
As g is GCD of a and b => GCD(x,y) = 1 (There will be no common factors of x,y)
(a-b) = g(x-y)
Here, we want to check if GCD(a-b, b) = g. If there exists

The Euclidean algorithm is based on the below facts:
->If we subtract the smaller number from larger (we reduce larger number), GCD doesn't change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
->Now instead of subtraction, if we divide the smaller number, the algorithm stops when the remainder is found to be 0.

NOTE:
1.) GCD(A,B) = GCD(B,R) Iff A = B*Q + R
2.) GCD(A,B) = GCD(A-B,B)
*/

// Euclidean Algorithm [TC: O(log(min(a, b)))]
int gcdEuclideanAlgo(int a, int b) // a and b can be any numbers.
{
    if (b == 0)
    {
        return a;
    }

    return gcdEuclideanAlgo(b, a % b);
}