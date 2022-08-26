/*
    I/P: 253
    O/P: 10
*/

#include <bits/stdc++.h>
using namespace std;

// 'd' is no of digits in n [TC: O(d),AS: O(d)]
int SumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + SumOfDigits(n / 10);
}
int main()
{
    cout << SumOfDigits(253);
    return 0;
}
