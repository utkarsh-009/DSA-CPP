/*
    I/P: arr[] = {1,4,13,-3,-10,5}
    O/P: Yes

    I/P: arr[] = {1,2}
    O/P: No
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
// Intution: Prefix Sum repeated => Somewhere subarray sum became 0 => Return true
// Also if prefix sum itself becomes 0 => Sum of Subarray until now is 0 => Return true
int ZeroSumSubarray(int arr[], int n)
{
    unordered_set<int> us; // to store prefix sum
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        // Prefix Sum repeated => Somewhere subarray sum became 0 => Return true
        if (us.find(prefix_sum) != us.end())
            return 1;
        // if prefix sum itself becomes 0 => Sum of Subarray until now is 0 => Return true
        if (prefix_sum == 0)
            return 1;
        us.insert(prefix_sum);
    }
    return 0;
}

int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << ZeroSumSubarray(arr, n);
}