#include <bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;       // size of hash table
    list<int> *table; // linked list stl

    // initalising size of hash table
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }

    // O(1): pushing the element k to list present at k%BUCKET index
    void insert(int k)
    {
        int i = k % BUCKET;
        table[i].push_back(k);
    }

    // O(1): searching the element k on list present on k%BUCKET index, present => true, else => false
    bool search(int k)
    {
        int i = k % BUCKET;
        for (auto x : table[i])
            if (x == k)
                return true;
        return false;
    }

    // O(1): remove function directly available to remove given element k from list present on k%BUCKET index
    void remove(int k)
    {
        int i = k % BUCKET;
        table[i].remove(k);
    }
};

int main()
{
    MyHash mh(7);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15);
}
