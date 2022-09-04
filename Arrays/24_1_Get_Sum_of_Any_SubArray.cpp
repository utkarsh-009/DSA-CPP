/*
    I/P: {2,8,33,24,23}, l = 2, r = 4
    O/P: 80 (33+24+23)
*/

#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum Technique [TC: O(n), AS: O(n)]
int findSubArraySum(int arr[], int n, int l, int r)
{
    int prefix_sum[n + 1];
    prefix_sum[0] = 0, prefix_sum[1] = arr[0];

    for (int i = 2; i < n; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    return prefix_sum[r] - prefix_sum[l - 1]; // getting sum of elements from l to r
}

int main()
{
    int arr[] = {2, 8, 33, 24, 23}, n = 5, l = 2, r = 4;
    cout << findSubArraySum(arr, n, l, r);
}
