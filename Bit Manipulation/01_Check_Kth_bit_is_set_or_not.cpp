/*
    I/P: n = 5, k = 1
    O/P: YES (000101)

    I/P: n = 8, k = 2
    O/P: NO (001000)
*/

#include <bits/stdc++.h>
using namespace std;

// Left Shift Approach [TC: O(1), AS: O(1)]
void isKthBitSet1(int n, int k)
{
    if (n & (1 << (k - 1)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// Right Shit Approach [TC: O(1), AS: O(1)]
void isKthBitSet2(int n, int k)
{
    if ((n >> (k - 1)) & 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n = 5, k = 1;
    isKthBitSet1(n, k);
    isKthBitSet2(n, k);
    return 0;
}
