/*
You are given a number N. Find the total number of setbits in the numbers from 1 to N.

Input: N = 3
Output: 4
Explaination:
1 -> 01, 2 -> 10 and 3 -> 11.
So total 4 setbits.
*/

#include <bits/stdc++.h>
using namespace std;

/*
ref: https://www.youtube.com/watch?v=g6OxU-hRGtY

Recurence relation: (Let x be largest power of 2 in N)
countBits(N) = (2^(x-1))*x + (N-2^(x)+1) + countBits(N-pow(2,x))
=> (pow(2,x-1)*x)+(N-pow(2,x)+1)+(countBits(N-pow(2,x)));
    • T1 = (pow(2,x-1)*x) =>
    counting all set bits of numbers that are less than largest power of 2
    • T2 = (N-pow(2,x)+1) =>
    Now, counting the most significant bit (msb) in numbers that are in range:
    [largest power of 2 <= Numbers <= N]
    • T3 = (countBits(N-pow(2,x))) =>
    Now for the other bits of number having range [largest power of 2 <= Numbers <= N] can be calculated
    in same manner as the msb are already calculated in T2. Hence, we recursively call the function again
    for the remaining numbers.
*/

// [TC: O(logN), AS: O(logN)]
int countSetBits(int N)
{
    if (N == 0)
    {
        return 0;
    }

    // Largest Power of 2 in N
    int x = (int)log2(N);

    int count = pow(2, x - 1) * x + (N - pow(2, x) + 1) + countSetBits(N - pow(2, x));

    return count;
}

int main()
{
    int n = 3;
    cout << countSetBits(n);
}
