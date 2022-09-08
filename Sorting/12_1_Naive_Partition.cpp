/*
    I/P: {3,8,6,12,10,7}, p = 5 (p: index of pivot)
    O/P: {3,6,7,8,12,10} or {6,3,7,12,8,10}..

Partition taking p as pivot means arr[i] <= arr[p] < arr[j]
*/

#include <bits/stdc++.h>
using namespace std;

// Naive[TC: O(n), AS: O(n)]
void partition(int arr[], int l, int h, int p)
{
    int temp[h - l + 1], index = 0;

    // for arr[i] < arr[p]
    for (int i = l; i <= h; i++)
    {
        if (arr[i] <= arr[p] && i != p)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    // inserting arr[p] after all arr[i] <= arr[p]
    temp[index] = arr[p];
    index++;

    // for arr[p] < arr[j]
    for (int j = l; j <= h; j++)
    {
        if (arr[j] > arr[p] && j != p)
        {
            temp[index] = arr[j];
            index++;
        }
    }

    // Updating original array using temp array
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[i - l];
    }
}

int main()
{

    int arr[] = {3, 8, 6, 12, 10, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    partition(arr, 0, n - 1, 5);

    for (int x : arr)
        cout << x << " ";
}
