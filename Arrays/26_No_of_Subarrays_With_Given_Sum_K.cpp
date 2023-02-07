/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,2,3], k = 3
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int NoOfSubarraySumWithGivenSum(vector<int> &nums, int k)
{
    int cnt = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (mp.find(sum - k) != mp.end())
        {
            cnt += mp[sum - k];
        }
        mp[sum]++;
    }
    return cnt;
}

int main()
{
    int k = 3;
    vector<int> v{1, 2, 3};
    cout << NoOfSubarraySumWithGivenSum(v, k);
}