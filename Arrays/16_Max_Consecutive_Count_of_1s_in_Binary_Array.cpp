/*
    I/P: arr[] = {0,1,1,0,1,0}
    O/P: 2

    I/P: arr[] = {1,1,1,1}
    O/P: 4
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(n), AS: O(1)]
int maxConsecutive1s(int arr[], int n)
{
    int res = 0;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            res = max(res, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return res;
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 1, 1}, n = 7;

    cout << maxConsecutive1s(arr, n);
}
