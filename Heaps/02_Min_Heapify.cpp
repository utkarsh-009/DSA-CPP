/*
Given a Binary Heap with one possible violation, fix the heap
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
class MinHeap
{
    int *arr;
    int size, capacity;

public:
    int left(i)
    {
        return 2 * i + 1;
    }

    int right(i)
    {
        return 2 * i + 2;
    }

    int parent(i)
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
};

int main()
{
}
