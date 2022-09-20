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
    1) top[]: This is of size k and stores indexes of top elements in all stacks.
    2) next[]: This is of size n and stores indexes of next item for the items in array arr[].
-> push(int x, int sn) // pushing element x into stack no sn
    1.) Push the element into => arr[freeTop]
    2.) The next free spot => next[free]

    // CODE //
    int i = freeTop; // Store index of next free slot
    freeTop = next[i]; // Update index of free slot to index of next slot
    // Update next of top and then top of stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;
    // Put the element into array
    arr[i] = x;

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

        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "\nStack Underflow\n";
            return INT_MAX;
        }

        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
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
