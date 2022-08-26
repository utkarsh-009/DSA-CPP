/*
    I/P: 7345
    O/P: NO

    I/P: 73437
    O/P: YES
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(No of Digits), AS: O(1)]
bool isPalidrome(int n)
{
    int rev = 0;
    int temp = n;

    while (temp != 0)
    {
        int last_dig = temp % 10;
        rev = rev * 10 + last_dig;
        temp /= 10;
    }

    return rev == n;
}