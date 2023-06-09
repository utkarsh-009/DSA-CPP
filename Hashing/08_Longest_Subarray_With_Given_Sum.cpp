/*
    I/P: arr[] = {10,5,2,7,1,9}, sum = 15
    O/P: 4 ({5, 2, 7, 1})

    I/P: arr[] = {-1,2,3}, sum = 6
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
Intution: Storing prefix sum with its index

curr_prefix_sum = prefix_sum1+sum,
- if prefix_sum1 i.e. curr_prefix_sum-sum exists in the map => Subarray with given sum exists
- if curr_prefix_sum is equal to give sum => Subarray with given sum exists
- Also save the new prefix in unordered_map

Conditions:
1.) mp.find(curr_prefix_sum-sum) != mp.end() => Subarray with given sum exists
2.) curr_prefix_sum == sum => Subarray with given sum exists
else return false;

// NOTE:  we use map to store index of new prefix sum.
1.) mp.find(curr_prefix_sum-sum) != mp.end() =>  max_len = max(max_len, i - m[prefix_sum - sum])
2.) curr_prefix_sum == sum =>  max_len = i + 1;
3.) mp.find(curr_prefix_sum) == mp.end() => mp[curr_prefix_sum] = i
*/
int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    int prefix_sum = 0, max_len = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
            max_len = i + 1;
        if (m.find(prefix_sum) == m.end())
            m.insert({prefix_sum, i});
        if (m.find(prefix_sum - sum) != m.end())
            max_len = max(max_len, i - m[prefix_sum - sum]);
    }
    return max_len;
}

int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;
    cout << largestSubarrayWithSumX(arr, n, sum);
}