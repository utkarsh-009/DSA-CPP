/*
    I/P: 4
    O/P: YES

    I/P: 6
    O/P: NO
*/

#include <bits/stdc++.h>
using namespace std;

// Naive  [TC: O(Total no of bits), AS:O(1)]
bool isPow2Naive(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n != 1)
    {
        if (n & 1) //  or n % 2 != 0
        {
            return false;
        }
        n = n >> 1; // or n = n/2
    }
    return true;
}

// Efficient (Using Brain Kerningam's Algorithm) [TC: O(1), AS: O(1)]
// As power of 2 has only one bit set => After unsetting that bit we will get 0 as output
bool isPow2Eff(int n)
{
    return (n != 0 && (n & (n - 1)) == 0);
}

int main()
{
    int n = 4;
    ((isPow2Naive(n)) ? cout << "YES" << endl : cout << "NO" << endl);
    ((isPow2Eff(n)) ? cout << "YES" << endl : cout << "NO" << endl);
}
