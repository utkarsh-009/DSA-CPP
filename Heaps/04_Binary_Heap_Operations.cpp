/*
Binary Heap Operations Implementation (Decrease Key, Delete and Build Heap)
-> Decrease Key: index and new value given => We have to update old value to new. Once updated, MinHeap Property should be maintained
-> Delete Key: delete key of given index. Once deleted, MinHeap Property should be maintained
-> Build Heap: Given random array, rearrange its elements to form min heap
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int size, capacity;

public:
    MinHeap(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
    }

    int getElem(int i)
    {
        return arr[i];
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int x)
    {
        if (size == capacity)
        {
            return;
        }
        size++;
        arr[size - 1] = x;

        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapifyRecur(int i) // Parent Index given as parameter
    {
        // Finding the indexes of left and right child
        int lIdx = left(i), rIdx = right(i);
        int smallest = i;

        // Checking if left child index actually exist (lIdx < size) and then checking if root is smaller than left child
        if (lIdx < size && arr[lIdx] < arr[i])
        {
            smallest = lIdx; // Update the smallest index
        }

        // Checking if right child index actually exist (rIdx < size) and then checking if right child is smallest
        if (rIdx < size && arr[rIdx] < arr[smallest])
        {
            smallest = rIdx;
        }

        if (smallest != i) // If root is not the smallest amongst root, left child, right child
        {
            swap(arr[i], arr[smallest]); // Swap smallest with root
            minHeapifyRecur(smallest);   // Recursievly Calling minHeapify for smallest index
        }
    }

    // Extract Min
    int extractMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            return arr[0];
        }

        int mini = arr[0];
        swap(arr[0], arr[size - 1]);
        minHeapifyRecur(0);

        return mini;
    }

    // Decrease Key [TC: O(logn)]
    void decreaseKey(int i, int x)
    {
        // Updating the key
        arr[i] = x;

        // To Maintain Min Heap Property
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Delete
    /*
    Intution:
    -> Perform decrease key with new value as -infinity (INT_MIN) on node we have to delete.
        ex: delete element on index 3 => decrease(3, INT_MIN)
        (NOTE: INT_MIN will become root of heap as min heap property is not violated after performing decrease key operation)
    -> Now we will call Extract Minimum to remove the element from heap
    */
    // [TC: O(logn), AS: O(h)]
    void delKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

// Min Heapify
void minHeapify(int arr[], int N, int i)
{
    int lIdx = 2 * i + 1, rIdx = 2 * i + 2;
    int smallest = i;
    if (lIdx < N && arr[lIdx] < arr[smallest])
    {
        smallest = lIdx;
    }

    if (rIdx < N && arr[rIdx] < arr[smallest])
    {
        smallest = rIdx;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, N, smallest);
    }
}

// Build Heap
/*
Intuition: The assumption for min heapify function is that when we call min heapify function for index i.
Its left and right should already be heapified. This is why we are iterating from bottom to top. As, when we
come to upper level, our lower level are already heapified.

Note: We start our iteration from bottom-most right-most internal node.
To get index of bottom-most right-most internal node,
    Parent of Last Node => ((size-1) - 1)/2
*/
// [TC: O(n) [Mathematical Proof], AS: O(h)]
void buildHeap(int arr[], int N)
{
    int startNode = (N - 2) / 2; // parent(n - 1);
    for (int i = startNode; i >= 0; i--)
    {
        minHeapify(arr, N, i);
    }
}

int main()
{
    MinHeap h(11);

    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(30);

    h.decreaseKey(0, 5);
    cout << h.getElem(0) << endl; // New minimum will be 5

    h.delKey(h.parent(1));
    cout << h.getElem(0) << endl; // New minimum will be 20

    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int N = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, N);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
