/*
Implement K stacks in a single array.
*/

#include <bits/stdc++.h>
using namespace std;

// SPACE OPTISMISED
/*
Intution:
->The idea is to use two extra arrays for efficient implementation of k stacks in an array.
    Extra Arrays:
    1) top[]: This is of size k and stores current indexes of top elements in all stacks.
    2) next[]: This is of size n and stores indexes of next items for each element in original array arr[].
    NOTE: next[] also helps us to find next free available spot in the array.
->Variables
    1.) k => No of stacks implemented in array
    2.) free_top => next available free slot in the original array
-> push(int x, int sn) // pushing element x into stack no sn
    1.) Push the element into => arr[freeTop]
    2.) The next free spot => next[free]
-> INITIALISATION:
    top[] => all to -1
    next[] => all i to i+1 except last index which is initialised as -1

    // CODE //
    int i = freeTop; // Store index of next free slot
    freeTop = next[i]; // Update index of free slot to index of next slot
    // Update next of top and then top of stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;
    // Put the element into array
    arr[i] = x;

-> next[]: - This is of size n and stores indexes of next items for each element in original array arr[]
    - next[] helps us to find next free available spot in the array
    - next[] also helps to link the other elements of stack with top.
    - if next[i] = -1 => arr[i] is the last element of stack
    - next free spot is stored in variable next[free]
    NOTE:
    1.) When ith position is empty (next free index to push) => it stores next position of top when the element is pushed
    2.) When ith position is filled (next top index after pop) => it stores next position of top if the element is popped
*/

struct KStacks
{
    int *arr, *next, *top;
    int k, freeTop, cap; // freeTop is the next available free slot in the original array arr.

    KStacks(int k1, int c)
    {
        k = k1, cap = c; // Initialising k and cap

        // Dynamically allocating size to arr, top, next array
        arr = new int[cap];
        top = new int[k];
        next = new int[cap];

        freeTop = 0;

        for (int i = 0; i < k; i++) // Initialising top array values as -1
        {
            top[i] = -1;
        }

        // next array is not only going to tell next element in stack but also next available free spot
        for (int i = 0; i < cap - 2; i++) // Intitalising next array values as i+1 from i = 0 to i = cap-2
        {
            next[i] = i + 1;
        }

        next[cap - 1] = -1; // Intitalising last element of next array as -1
    }

    bool isFull() { return (freeTop == -1); }

    bool isEmpty(int sn) { return (top[sn] == -1); }

    void push(int x, int sn)
    {
        if (isFull())
        {
            cout << "\nStack Overflow\n";
            return;
        }

        // Store the index of current free top
        int i = freeTop;

        // Update the next free top using next[i]
        freeTop = next[i];

        // Storing next[i] as top[sn] which will help to link new element to whatever that is present in the stack
        // This will help us, when ith element is popped => we get the next element using next[i]
        next[i] = top[sn];

        // Updating the current top of the given stack number. The new top will be set to current free top.
        top[sn] = i;

        // Update the element at current free top
        arr[i] = x;
    }

    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "\nStack Underflow\n";
            return INT_MAX;
        }

        // Element i.e. to be popped will be at current top of the stack.
        // Using top[sn], we get the top index of given stack no sn.
        int i = top[sn]; // stores current top index

        // The next top index after pop operation will be updated in top[sn] using next[i]
        top[sn] = next[i];

        // The next free index at ith position will be updated using freeTop
        next[i] = freeTop;

        // The free top is also updated as after pop operation is performed, the current top index will be freeTop
        freeTop = i;

        return arr[i];
    }
};

int main()
{
    int k = 3, n = 10;
    KStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

    return 0;
}
