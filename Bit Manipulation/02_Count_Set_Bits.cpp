/*
    I/P: n = 5
    O/P: 2

    I/P: n = 0
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(Total no of bits),AS: O(1)]
int countSetBits1(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n & 1 == 1) // or (n % 2 != 0)
        {
            cnt++;
        }
        n = n >> 1; // or (n = n/2)
    }
    return cnt;
}

/*
    Brain Kerningam's Algorithm: This algorithm is used to unset the right most bit
    When we subtract 1 from a number 'n' then all the bits which are 0's after last set bit become 1 and the last set bit becomes 0.
    Hence, (n&(n-1)) => Unsets all the bits after the second last set bit.
*/

// Efficient (Using Brain Kerningam's Algorithm) [TC: O(No of Set Bits), AS: O(1)]
// We are trying to unset, a set bit in every iteration.
int countSetBits2(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        cnt++;
    }

    return cnt;
}

int main()
{
    int n = 5;
    cout << countSetBits1(5) << endl;
    cout << countSetBits2(5) << endl;
}
