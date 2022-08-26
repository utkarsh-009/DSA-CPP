/*
    I/P: a = 4, b = 6
    O/P: 2

    I/P: a = 7, b = 13
    O/P: 1

NOTE: GCD or HCF
This question can interpreted as a triangle of 4*6 size units,
then the largest size of square that can fill the rectangle completely will be square of size 2
*/

#include <bits/stdc++.h>
using namespace std;

/*
We know the fact that HCF/GCD of a,b cannot be greater than min(a,b)
Hence, we iterate number from min(a,b) to 1. As soon as, we get the number which divides both a and b => the number is GCD
*/
// Naive: [TC: O(min(a,b)), AS: O(1)]
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
----------------------------------------------------------
||  Euclidean Algorithm                                 ||
||  1.) GCD(a,b) = GCD(a-b, a), Note: a > b && a != b   ||
||  2.) GCD(a,b) = GCD(b, a%b), Note: b != 0            ||
----------------------------------------------------------

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

// Euclidean Algorithm [TC: O(min(a,b)), AS: O(min(a,b))]
int gcdEuclideanAlgo(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcdEuclideanAlgo(a - b, b);
    return gcdEuclideanAlgo(a, b - a);
}

// Optimised Euclidean Algorithm [TC: O(log(min(a,b)), AS: O(log(min(a,b))]
int gcdEuclideanAlgoOptimised(int a, int b) // No Initial Condition Reqd
{
    if (b == 0)
    {
        return a;
    }

    return gcdEuclideanAlgo(b, a % b);
}