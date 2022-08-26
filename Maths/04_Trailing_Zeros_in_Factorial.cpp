/*
    I/P: 5(120)
    O/P: 1

    I/P: 0(1)
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

/*
 Efficient Solution: Count no of 2's & 5's in pair
 NOTE: No of 5's < No of 2's in Prime Factorisation of a Factorial => We only need to count no of 5's in Prime Factorisation

 Trailing Zero Count = [n/5] + [n/25] + [n/125].....
*/

// TC: O(log(n)), AS: O(1), No overflow
int countTrailingZeroes(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }

    return res;
}