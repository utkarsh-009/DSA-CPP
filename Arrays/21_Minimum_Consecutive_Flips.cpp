/*
Given a binary array, we need to find the minimum of number of group flips to make all array elements same.
In a group flip, we can flip any set of consecutive 1s or 0s.
    I/P: {1,1,0,0,0,1}
    O/P: From 2 to 4

    I/P: {1,0,0,0,1,0,0,1,1,1,1}
    O/P: From 1 to 3
         From 5 to 6

    I/P: {1,1,1}
    O/P:

    I/P: {0,1}
    O/P: From 0 to 0
         From 1 to 1
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
void printMinConsecutiveFlips(int arr[], int n)
{
    // We are never going to flip element (0/1) i.e. present in 1st group
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1]) // Checking if group has changed or not
        {
            if (arr[i] != arr[0]) // Comparing if the element to be flipped is equal to element present in 1st group
            {
                cout << "From " << i << " to "; // Printing index of first element of the group that is to be flipped
            }
            else // Printing index of last element of the group that is to be flipped
            {
                cout << i - 1 << endl;
            }
        }
    }
    if (arr[n - 1] != arr[0]) // if last element of array is part of group that is to be flipped
    {
        cout << n - 1 << endl;
    }
}

int main()
{
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0}, n = 9;

    printMinConsecutiveFlips(arr, n);
}
