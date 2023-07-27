/*
Given a Binary Heap with one possible violation, fix the heap
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

    /*
    Intution: We pass index of node to minHeapify function, which maybe violating min heap property
    This function fixes the subtree under the given node by making sure that root of the subtree has minimum value
    */
    // Recursive [TC: O(logn), AS: O(h)] NOTE: Iterative Soln takes AS: O(1)
    void minHeapifyRecur(int i) // Parent Index given as parameter
    {
        // We find the smallest amongst: left, right, root. If root is not smallest => violation.

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
};

int main()
{
    MinHeap h(5);
    h.insert(3);
    h.insert(24);
    h.insert(15);
    h.insert(20);

    return 0;
}
