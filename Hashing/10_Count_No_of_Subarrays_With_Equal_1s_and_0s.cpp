/*
    Input:
    n = 7
    A[] = {1,0,0,1,0,1,1}
    Output: 8
    Explanation: The index range for the 8 sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4),
    (4, 5) ,(2, 5), (0, 5), (1, 6)

    Input:
    n = 5
    A[] = {1,1,1,1,0}
    Output: 1
    Explanation: The index range for the
    subarray is (3,4).
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
// Convert all 0's to -1. And apply same technique as counting no of subarrays with given sum = 0
int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ((arr[i] == 0) ? arr[i] = -1 : arr[i] = 1);
    }

    unordered_map<int, int> mp;
    int cnt = 0;
    int preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == 0)
        {
            cnt++;
        }
        if (mp.find(preSum) != mp.end())
        {
            cnt += mp[preSum];
        }

        mp[preSum]++;
    }

    return cnt;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSubarrWithEqualZeroAndOne(arr, n);
}
