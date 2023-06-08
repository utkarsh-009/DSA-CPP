/*
    I/P: arr[] = {5,8,6,13,3,-1}, sum = 22
    O/P: False

    I/P: arr[] = {3,2,5,6}, sum=10
    O/P: True
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
Intution: curr_prefix_sum = prefix_sum1+sum,
- if prefix_sum1 i.e. curr_prefix_sum-sum exists in the map => Subarray with given sum exists
- Also if curr_prefix_sum is equal to give sum => Subarray with given sum exists

Conditions:
1.) mp.find(curr_prefix_sum-sum) != mp.end() => Subarray with given sum exists
2.) curr_prefix_sum == sum => Subarray with given sum exists
else return false;

// NOTE: to count such subarrays, we use map to store frequency of prefix sums.
1.) mp.find(curr_prefix_sum-sum) != mp.end() => cnt += mp[curr_prefix_sum-sum];
2.) curr_prefix_sum == sum =>  cnt++;
*/
bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (s.find(pre_sum - sum) != s.end())
            return true;
        if (pre_sum == sum)
            return true;
        s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum = 22;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << isSum(arr, n, sum);
}