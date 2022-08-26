/*
    I/P: arr[] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;
    O/P: 5 6

*/

#include <bits/stdc++.h>
using namespace std;

/*
    Let's take an example, where a and b are the only two odd occuring numbers
    res => a^....^b = a^b
    S1: Now we will check for the last set bit in res, this will help us to differentiate between a and b.
    As the kth set bit in res implies that a and b had different bits at kth place (1/0 or 0/1)

    S2: Now we will seperate a & b in different groups on the basis of whether the kth bit is set or not

    S3: Now independently taking the XOR of the two groups will give us value of a and b
*/

// Efficient: Using XOR  [TC: O(n), AS: O(1)]
void twoOddOccuringNumbers(int arr[], int n)
{
    int XOR = 0, a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        XOR ^= arr[i];
    }
    // (XOR) & (~(XOR - 1)) => This gives binary representation of the number (XOR) with only set bit as last set bit.
    int only_last_set_bit = (XOR) & (~(XOR - 1)); // This will help in division of groups
    for (int i = 0; i < n; i++)
    {
        if (((only_last_set_bit)&arr[i]) == 1)
        {
            a ^= arr[i];
        }
        else
        {
            b ^= arr[i];
        }
    }

    cout << a << " " << b << endl;
}

int main()
{
    int arr[] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7}, n = 10;

    twoOddOccuringNumbers(arr, n);
}
