/*
Finding Maximum Sum of K Consecutive elements
    I/P: [1,8,30,-5,20,7], k = 3
    O/P: 45
*/

#include <bits/stdc++.h>
using namespace std;

// Using Sliding Window Technique [TC: O(n), AS: O(1)]
int maxKConsecutiveElementSum(int arr[], int n, int k)
{
    int maxKSum = INT_MIN, sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    maxKSum = max(maxKSum, sum);

    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        maxKSum = max(maxKSum, sum);
    }

    return maxKSum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7}, n = 6, k = 3;

    cout << maxKConsecutiveElementSum(arr, n, k);
}
