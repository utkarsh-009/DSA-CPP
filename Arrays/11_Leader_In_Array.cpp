/*
An element is called the leader of an array if there is no element strictly greater than it on the right side.

    I/P: {7,10,4,3,6,5,2}
    O/P: 10 6 5 2

    I/P: {10, 20, 30}
    O/P: 30
*/

#include <bits/stdc++.h>
using namespace std;

// Prints leaderss from Last [TC: O(n), AS: O(1)]
void leaders(int arr[], int n)
{
    int curr_max = 0; // Updating curr max everytime inorder to check if all the element at right are smaller than curr_max
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > curr_max)
        {
            cout << arr[i] << " ";
            curr_max = arr[i];
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
    // int arr[] = {10, 20, 30}, n = 3;

    leaders(arr, n);
}
