/*
Implementation of Min Heap
Min heap internally represented as an array
    root = (i-1)/2
    left = 2*i + 1
    right = 2*i + 2
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

    // left child index
    int left(int i)
    {
        return 2 * i + 1;
    }

    // right child index
    int right(int i)
    {
        return 2 * i + 2;
    }

    // parent index
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // insert function
    void insert(int x)
    {
        if (size == capacity)
        {
            return;
        }
        size++;
        arr[size - 1] = x;

        // Inserting x into appropriate index where it satisfies heap condition
        int i = size - 1;
        while (i != 0 && arr[parent(i)] > arr[i]) // (i != root) && (parent of i > arr[i])
        {
            swap(arr[i], arr[parent(i)]); // Swapping when (parent of i > arr[i])
            i = parent(i);                // Updating index of x
        }
    }
};

int main()
{
    MinHeap h(5);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);

    cout << h.left(0);
    return 0;
}
