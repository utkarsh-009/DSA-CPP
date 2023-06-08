/*
Other Open Addressing Techniques:
    Quadratic Probing: hash(key,i) = (h(key)+curr_sz*curr_sz)%cap
    Double Hashing: hash(key,i) = (h1(key)+curr_sz*h2(key))%cap
*/
#include <bits/stdc++.h>
using namespace std;

// Linear Probing Implementation
struct MyHash
{
    int *arr;
    int cap, size;

    // Initalising Hash Table with -1
    MyHash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        for (int i = 0; i < cap; i++)
            arr[i] = -1;
    }

    // hash function
    int hash(int key)
    {
        return key % cap;
    }

    // Inserting Element
    bool insert(int key)
    {
        // if size of hash table is equal to its capacity => no more elements can be stored
        if (size == cap)
            return false;

        // hash value of key
        int i = hash(key);

        // if we find empty slot i.e -1 (empty) or -2 (deleted), or we found that element already exists => break
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
            i = (i + 1) % cap;

        // if element already exists
        if (arr[i] == key)
        {
            return false;
        }
        // inserting the element on empty spot
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }

    // Searching element
    bool search(int key)
    {
        int h = hash(key);
        int i = h;

        // Searching element till we find empty spot
        while (arr[i] != -1)
        {
            // if found => return true
            if (arr[i] == key)
            {
                return true;
            }

            i = (i + 1) % cap;

            // one complete iteration completed
            if (i == h)
            {
                return false;
            }
        }
        return false;
    }

    // Erasing element from hash table is same as searching
    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        // Searching element till we find empty spot
        while (arr[i] != -1)
        {
            // If we found element => Mark it as erased(-2)
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;

            // one complete iteration completed
            if (i == h)
                return false;
        }
        return false;
    }
};

int main()
{
    MyHash mh(7);
    mh.insert(49);
    mh.insert(56);
    mh.insert(72);
    if (mh.search(56) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    mh.erase(56);
    if (mh.search(56) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
