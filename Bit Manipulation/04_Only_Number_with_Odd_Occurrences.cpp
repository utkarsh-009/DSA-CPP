/*
    I/P:  n = 9, arr = {4, 3, 4, 4, 4, 5, 5, 3, 3}
    O/P: 3
*/

#include <bits/stdc++.h>
using namespace std;

/*
Properties of XOR:
    x^0 = x
    x^y = y^x
    x^x = 0
    (x^y)^z = x^(y^z)
*/

// Using XOR Operator  [TC: O(n),AS: O(1)]
int findOnlyOddOcc(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res ^= arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {4, 3, 4, 4, 4, 5, 5, 3, 3}, n = 9;

    cout << findOnlyOddOcc(arr, n);
}
