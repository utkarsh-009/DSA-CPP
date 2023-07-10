/*
Given an integer array nums, return the length of the longest strictly increasing
subsequence.

    I/P: nums = [10,9,2,5,3,7,101,18]
    O/P: 4 ([2,3,7,101])

    I/P: nums = [7,7,7,7,7,7,7]
    O/P: 1 ([7])
*/

#include <bits/stdc++.h>
using namespace std;

// Memoisation [TC: O(n*n), AS: O(N)]
int memoDP(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx >= nums.size())
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int lis = 1;
    for (int i = idx + 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[idx])
        {
            lis = max(lis, 1 + memoDP(nums, i, dp));
        }
    }

    return dp[idx] = lis;
}

// Tabulation [TC: O(N*N), AS: O(N)] (No recursion overhead)
int tabDP(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            // Including current element to suseq if nums[i] > nums[j]
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// Most Efficient: Using Lowerbound [TC: O(nlogn), AS: O(n)]
/*
Intuition behind the binary search code to solve the longest increasing subsequence problem is to maintain a list of
the smallest tail elements of all increasing subsequences found so far.
    - Using lower_bound we find the smallest element greater than or equal to nums[i]
    - If such an index j is found, we update tails[j] to be nums[i], since we have found a smaller tail element for the
    increasing subsequence of length j+1.
    - If no such index j is found, we append nums[i] to tails, since it forms a new increasing subsequence of length
    tails.size()+1.
*/
int efficientLis(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lis;

    for (int i = 0; i < n; i++)
    {
        // find the smallest element greater than or equal to nums[i] in lis vector
        auto lb = lower_bound(lis.begin(), lis.end(), nums[i]);
        // if no lowerbound found => nums[i] is currently largest in the lis. Hence, we add it to lis
        if (lb == lis.end())
        {
            lis.push_back(nums[i]);
        }
        // if lowerbound found => nums[i] is smaller that the largest element in lis. Hence, we replace that largest element to nums[i]
        else
        {
            *lb = nums[i];
        }
    }

    return lis.size();
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;
    int ans = 0;

    // Memoisation: O(N*N)
    // vector<int> dp(n, -1);
    // for (int i = 0; i < n; i++)
    // {
    //     ans = max(ans, memoDP(nums, i, dp));
    // }

    // Tabulation: (No recursion overhead)
    ans = tabDP(nums);
    cout << ans << endl;

    // Efficient: Fastest Approach
    ans = efficientLis(nums);
    cout << ans << endl;
}
