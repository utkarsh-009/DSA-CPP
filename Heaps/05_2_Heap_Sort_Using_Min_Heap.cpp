/*
    I/P: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    O/P: 17 15 13 10 9 8 6 5 4 3 1
*/

#include <bits/stdc++.h>
using namespace std;

// minHeap [TC: O(logn), AS: O(h)]
void minHeapify(int arr[], int n, int i)
{
    int lIdx = 2 * i + 1, rIdx = 2 * i + 2;
    int smallest = i;
    if (lIdx < n && arr[lIdx] < arr[smallest])
    {
        smallest = lIdx;
    }

    if (rIdx < n && arr[rIdx] < arr[smallest])
    {
        smallest = rIdx;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// build min heap [TC: O(n), AS: O(h)]
void buildMinHeap(int arr[], int n)
{
    int startNode = ((n - 1) - 1) / 2; // parent(n - 1);
    for (int i = startNode; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

// Descending Order Sort [TC: O(nlogn), AS: O(h)]
void heapSortDesc(int arr[], int n)
{
    buildMinHeap(arr, n); // To build heap from random array
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);  // Swapping the minimum element to last pos
        minHeapify(arr, i, 0); // To maintain min heap property after modification
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSortDesc(arr, n);

    for (int x : arr)
    {
        cout << x << " ";
    }
}
