/*
    I/P: arr[] = {2,3,-8,7,-1,2,3}
    O/P: 11

    I/P: arr[] = {-6,-1,-8}
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

// Using Kadanes Algorithm [TC: O(n), AS: O(1)]
/*
Kadanes Algo Intution:
    maxSS: Keeps track of maximum of current maximum subarray sum
    if sum + arr[i] > 0 => arr[i] may become part of the maximum subarray sum
    else => arr[i] can never become part of the maximum subarray sum => We find for new subarray sum by making sum = 0;

NOTE: If arr[i] is the candidate to become part of maxSS => We update maxSS by maxSS = max(maxSS, sum)
*/

int maxSubarraySum(int arr[], int n)
{
    int maxSS = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > 0)
        {
            sum += arr[i];
        }
        else
        {
            sum = 0; // Finding new subarray sums
        }
        maxSS = max(maxSS, sum); // Updating the maximum of current maximum subarray sum
    }

    return maxSS;
}

int main()
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3}, n = 7;

    cout << maxSubarraySumDivAndCon(arr, n);
}
