/*
Get Min: Gives the minimum element without changing the heap
Extract Minimum: Returns and removes minimum element from heap and makes a new heap with elements
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

    /*
    Intution: Swap root element with last element (swap(arr[0], arr[size-1])) and decrease size (size--).
    Now call minHeapify for root.
    */
    // [TC: O(logn), AS: O(logn)]
    int extractMin()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int mini = arr[0];

        swap(arr[0], arr[size - 1]);
        size--;
        minHeapifyRecur(0);

        return mini;
    }
};

int main()
{
    MinHeap h(11);
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(30);
    cout << h.extractMin() << " ";

    return 0;
}
