/*
Finding the length of the longest subarray that has alternating even odd elements.
    I/P: {10,12,14,7,8}
    O/P: 3

    I/P: {7,10,13,14}
    O/P: 4

    I/P: {10,8,14}
    O/P: 1
*/

#include <bits/stdc++.h>
using namespace std;

// My Soln Using Kadanes Algo [TC: O(n), AS: O(1)]
int maxAlterEOLen(int arr[], int n)
{
    int max_len = 0, len = 1;
    bool prevO = false, prevE = false;

    ((arr[0] % 2 == 0) ? prevE = true : prevO = true);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 == 0 && prevO)
        {
            len++;
            prevO = false;
            prevE = true;
        }
        else if (arr[i] % 2 != 0 && prevE)
        {
            len++;
            prevE = false;
            prevO = true;
        }
        else
        {
            len = 1;
        }
        max_len = max(max_len, len);
    }

    return max_len;
}

// GFG Soln Using Kadanes Algo [TC: O(n), AS: O(1)]
int maxEvenOdd(int arr[], int n)
{
    int res = 1;
    int curr = 1;

    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;

            res = max(res, curr);
        }
        else
            curr = 1;
    }

    return res;
}

int main()
{
    int arr[] = {10, 8, 14}, n = 3;

    cout << maxAlterEOLen(arr, n);
}
