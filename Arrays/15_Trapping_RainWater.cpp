/*
Trapping Rain Water Problem: Height of Bars are given, we have to find total amount of water we can collect between these bars
    I/P: arr[] = {2, 0, 2}
    O/P: 2

    I/P: arr[] = {3, 0, 1, 2, 5}
    O/P: 6 (3 + 2 + 1)

    I/P: arr[] = {1, 2, 3} or {3, 2, 1}
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*n), AS: O(1)]
/*
Facts: Leftmost and Rightmost Bars (first and the last bar) cannot store water at all, they may be used for support
Intution:
-> We will iterate through all the bars excluding (first and the last bar)
-> In every iteration for the current bar, we will find lmax bar (j = 0 to j < i) and rmax (j = i+1 to j < n). These lmax and rmax acts as supporting blocks
-> min(lmax, rmax) => The level upto which water can rise
-> But in some cases there will be height of current block itself which means the current block is also taking up some area.
   Hence, we will subtract area taken up by current block => min(lmax, rmax) - arr[i] => To get the actual area in which water can be trapped
*/
int getWaterAmountNaive(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++) // Leftmost and Rightmost Bars cannot store water at all => Bar 0th and Bar (n-1)th ignored
    {
        // arr[i] => current bars
        int lmax = arr[i];
        for (int j = 0; j < i; j++) // Finding Leftmost Max Height Bar
        {
            lmax = max(lmax, arr[j]);
        }

        int rmax = arr[i];
        for (int j = i + 1; j < n; j++) // Finding Rightmost Max Height Bar
        {
            rmax = max(rmax, arr[j]);
        }

        res += min(rmax, lmax) - arr[i]; // The amount of water that particular Bar can hold is min(rmax, lmax) - current bar height
    }
    return res;
}

// Precomputation of LeftMax and RightMax for every Bar [TC: O(n), AS: O(n)]
/*
Precomputing lmax and rmax for every current block
*/
int getWaterAmount(int arr[], int n)
{
    int res = 0;

    int lMax[n], rMax[n];
    lMax[0] = arr[0];

    for (int i = 1; i < n - 1; i++)
    {
        lMax[i] = max(lMax[i - 1], arr[i]);
    }

    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i + 1], arr[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        res += min(lMax[i], rMax[i]) - arr[i];
    }

    return res;
}

int main()
{
    int arr[] = {3, 0, 1, 2, 5}, n = 5;

    cout << getWaterAmount(arr, n);
}
