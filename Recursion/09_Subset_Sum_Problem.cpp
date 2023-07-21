/*
Given an array of non-negative integers, and a value sum, determine if there is a subset
 of the given set with sum equal to given sum.

Input: N = 6, arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
*/
#include <bits/stdc++.h>
using namespace std;

// [TC: O(2^n), [AS: O(n) Recursion call stack size]]
bool isSubsetSum(vector<int> &arr, int sum, int idx)
{
    if (idx >= arr.size())
        return false;

    if (sum == 0)
        return true;

    return isSubsetSum(arr, sum - arr[idx], idx + 1) || isSubsetSum(arr, sum, idx + 1);
}

int main()
{
    int n = 6, sum = 9;
    vector<int> arr{3, 34, 4, 12, 5, 2};
    cout << isSubsetSum(arr, sum, 0) << endl;
}
