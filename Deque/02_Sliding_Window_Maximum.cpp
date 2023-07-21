/*
Maximum of all subarrays in of size k:
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input: N = 9, K = 3, arr[] = 1 2 3 1 4 5 2 3 6
Output: 3 3 4 5 5 5 6
*/

#include <bits/stdc++.h>
using namespace std;

/*
NOTE:
- Deque should be of size k or less than k.
- We will store index for better accessbility.
- Should be in descending order, as if not then the elements that are stored will
be irrelevant since we would have already gotten the maximum element in next window.
- Also descending order to be maintained because we will able to store max element of each window in front of deque
*/
vector<int> printMaxSubArraySizeK(int arr[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        // descending:
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // maximum of first window
    ans.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++)
    {
        // maintaining window size k
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    return ans;
}