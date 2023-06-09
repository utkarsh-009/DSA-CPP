/*
Given two binary arrays arr1[] and arr2[] of same size N. Find length of the longest common span [i, j]
where j>=i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].

    Input:
    N = 6
    Arr1[] = {0, 1, 0, 0, 0, 0}
    Arr2[] = {1, 0, 1, 0, 0, 1}
    Output: 4
    Explanation: The longest span with same
    sum is from index 1 to 4 following zero
    based indexing.
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
Intution:
If arr1[] and arr2[] has a span [i,j] with equal sum, then their difference of elements from [i,j] will be equal 0

Approach:
We create a temp[] which will be equal to, temp[i] = arr1[i]-arr2[i] i.e. difference between elements of arr1 and arr2.
**Then, we apply the technique to find max_len of subarray with sum equal to 0**
*/
int longestCommonSum(bool arr1[], bool arr2[], int n)
{
    unordered_map<int, int> mp;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr1[i] - arr2[i];
    }

    int prefix = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += temp[i];
        if (prefix == 0)
        {
            max_len = i + 1;
        }

        if (mp.find(prefix) != mp.end())
        {
            max_len = max(max_len, i - mp[prefix]);
        }
        else
        {
            mp[prefix] = i;
        }
    }

    return max_len;
}

int main()
{
    int n = 6;
    bool arr1[] = {0, 1, 0, 0, 0, 0};
    bool arr2[] = {1, 0, 1, 0, 0, 1};

    cout << longestCommonSum(arr1, arr2, n);
}
