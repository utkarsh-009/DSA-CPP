/*
    I/P: arr[] = {5,-2,3,4}
    O/P: 12 (5+3+4)

    I/P: arr[] = {2,3,-4}
    O/P: 5
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int maxSubarraySumDivAndCon(int arr[], int n)
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
    int arr[] = {8, -4, 3, -5, 4}, n = 5;

    cout << maxCircularSumSubarray(arr, n);
}
