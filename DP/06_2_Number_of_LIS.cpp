/*
Given an integer array nums, return the number of longest increasing subsequences.

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
*/

#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> length(n, 1); // length[i] stores the lis length ending at index 'i'
    vector<int> count(n, 1);  // count[i] stores the number of lis ending at index 'i'

    // We are actually storing the maximum subsequence length till the ith index along with the count of
    // subsequences that can be formed with that maximum length till the ith index.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                // If the current stored length is not the lis,
                // we update the length[i] and reset the count to 0 along with updating lis of length[i]
                if (length[i] < length[j] + 1)
                {
                    length[i] = length[j] + 1;
                    // We discard the previous subsequence length count as it is no longer the lis, and set it as 0.
                    count[i] = 0;
                }

                // If the current length is equal to the longest increasing subsequence length found so far,
                // we increase the count as we found another maximum length subsequence.
                if (length[i] == length[j] + 1)
                {
                    // count[i] is incremented by count of lis till jth index, i.e. count[j]
                    count[i] += count[j];
                }
            }
        }
    }

    int ans = 0;
    int lis = *max_element(length.begin(), length.end());
    for (int i = 0; i < n; i++)
    {
        if (length[i] == lis)
        {
            ans += count[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> nums{1, 3, 5, 4, 7};
    cout << findNumberOfLIS(nums);
}