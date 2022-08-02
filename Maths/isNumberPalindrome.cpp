#include <bits/stdc++.h>
using namespace std;

/*
n = 78787 => Yes
n = 8999 => No
*/

//Checking if reverse of original number equal to original number 
// true => Number is Palindrome, false => Number is not Palindrome
bool isNumPalindrome(int n)
{
    int num = n, rev = 0;
    while (num != 0)
    {
        int ld = num % 10;
        rev = rev * 10 + ld;
        num = num / 10;
    }

    return (rev == n);
}