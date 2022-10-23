/*
Given an unsorted array Arr of size N of positive integers.
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array.
Find these two numbers.

    Input:
    N = 2
    Arr[] = {2, 2}
    Output: 2 1

    Input:
    N = 3
    Arr[] = {1, 3, 3}
    Output: 3 2

*/

#include <bits/stdc++.h>
using namespace std;

// Using XOR [TC: O(n), AS: O(1)]
/*
-> The idea is based on: (1 ^ 2 ^ 3 ^ .. ^ n) ^ (1 ^ 2 ^ 3 ^ .. ^ n) = 0
    0 ^ a ^ b ^ b ^ b = a ^ b , xor1 = a ^ b (a, b will be missing and repeating numbers)
-> So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 and
    divide the elements of the array in two sets – one set of elements with the same bit set
    and other set with same bit not set.
-> By doing so, we will get x in one set and y in another set. Now if we do XOR of all the elements in first set,
    we will get x, and by doing same in other set we will get y.


*/
vector<int> findRepAndMis(vector<int> arr, int n)
{

    vector<int> ans(2);
    int xor1 = 0;

    //
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
    }

    // Finding right most set bit as it will be the one when number 'x' and 'y' are having different bits
    int rsb = xor1 & -xor1; // or rsb = xor1 & ~(xor1 - 1)
    int x = 0, y = 0;

    // To find values of x,y with array (Moving 'x' and 'y' into two different sets)
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if ((val & rsb) == 0)
        {
            x ^= val;
        }
        else
        {
            y ^= val;
        }
    }

    // Finding value of x and y
    for (int i = 1; i <= n; i++)
    {
        if ((i & rsb) == 0)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    // To check between x and y that which no is missing and which is repeating
    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (val == x)
        {
            ans[0] = x;
            ans[1] = y;
        }
        else if (val == y)
        {
            ans[0] = y;
            ans[1] = x;
        }
    }

    return ans;
}

int main()
{
    int n = 3;
    vector<int> arr{1, 3, 3};

    for (int x : findRepAndMis(arr, n))
    {
        cout << x << " ";
    }
}
