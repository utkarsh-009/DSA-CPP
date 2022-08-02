#include <bits/stdc++.h>
using namespace std;

/*
n = 5 (120) => 1
n = 0 (1)  => 0
*/

// Efficient Solution: Count no of 2's & 5's in pair
// NOTE: No of 5's < No of 2's in Prime Factorisation => We only need to count no of 5's in Prime Factorisation

// Trailing Zero Count = [n/5] + [n/25] + [n/125].....
int coutTrailingZeroes(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }

    return res;
}
// TC: O(log(n)), AS: O(1), No overflow