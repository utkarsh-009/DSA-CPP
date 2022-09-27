/*
    I/P: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    O/P: 1 3 4 5 6 8 9 10 13 15 17
*/

#include <bits/stdc++.h>
using namespace std;

// maxHeap: [TC: O(logn), AS: O(h)]
void maxHeapify(int arr[], int n, int i)
{
    int largest = i, lIdx = 2 * i + 1, rIdx = 2 * i + 2;
    if (lIdx < n && arr[lIdx] > arr[largest])
    {
        largest = lIdx;
    }
    if (rIdx < n && arr[rIdx] > arr[largest])
    {
        largest = rIdx;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// build max heap [TC: O(n), AS: O(h)]
void buildMaxHeap(int arr[], int n)
{
    int startIdx = ((n - 1) - 1) / 2; // parent(n-1)
    for (int i = startIdx; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

// Ascending Order Sort [TC: O(nlogn), AS: O(h)]
void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);  // Swapping max element with last element
        maxHeapify(arr, i, 0); // To maintain max heap property after modification
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    for (int x : arr)
    {
        cout << x << " ";
    }
}
