/*
Hoares Partition: Taking First element as Pivot
    I/P: {3,8,6,12,10,7}, p = 5 (p: index of pivot)
    O/P: {3,6,7,8,12,10} or {6,3,7,12,8,10}..

Partition taking p as pivot means arr[i] <= arr[p] < arr[j]
*/

#include <bits/stdc++.h>
using namespace std;

// Hoares Partition  [TC: O(n), AS:O(1)]
int hPartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1; // starting i and j iterators before start and after end respectively
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot); // incrementing i until we get, arr[i] > pivot
        do
        {
            j--;
        } while (arr[j] > pivot); // decrementing i until we get, arr[j] < pivot

        if (i >= j) // array partitioned
        {
            return j; // return j as pivot index
        }

        swap(arr[i], arr[j]); // as, arr[i] > pivot && arr[j] < pivot => swap(arr[i], arr[j])
    }
}

int main()
{
    int a[] = {5, 3, 8, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nNew pivot(index) is: " << hPartition(a, 0, n - 1) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
