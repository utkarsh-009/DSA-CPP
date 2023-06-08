/*
    I/P: arr[] = {3,2,8,15,-8}, sum=17
    O/P: True

    I/P: arr[]  = {2,1,6,3}, sum=6
    O/P: False
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS:O(n)]
// Intution: x2 = sum-x1 => if (sum-x1) is in map => x1+x2 = sum. Hence, pair with given sum exists.
int pairWithSumX(int arr[], int n, int X)
{
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        if (us.find(X - arr[i]) != us.end())
            return 1;

        us.insert(arr[i]);
    }
    return 0;
}

int main()
{
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 14;

    cout << pairWithSumX(arr, n, X);
    return 0;
}
