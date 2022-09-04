/*
We have to find whether the array has equilibrium point
    I/P: {3,4,8,-9,20,6}
    O/P: YES (3+4+8-9 = 6) [4]

    I/P: {0,2,-3}
    O/P: NO [-1]
*/

#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum Technique [TC: O(n), AS: O(1)]
int findEquilibriumPoint(int arr[], int n)
{
    int total_sum = 0;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    int curr_sum = 0; // curr sum
    for (int i = 0; i < n; i++)
    {
        if (curr_sum == total_sum - arr[i]) // if curr sum at some point equal to total_sum - arr[i] => Equilibrium Point
        {
            return i;
        }
        curr_sum += arr[i];
        total_sum -= arr[i];
    }

    return -1;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6}, n = 6;

    cout << findEquilibriumPoint(arr, n);
}
