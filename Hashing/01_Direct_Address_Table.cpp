/*
Imagine a situation where we have 1000 keys with values (0 to 999),
We have to implement Search, Insert, Delete Operation is O(1)
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(1) for all operations, AS: O(size)]
struct DirectAddressTable
{
    int table[1000] = {0};

    // O(1)
    void insert(int i)
    {
        table[i] = 1;
    }

    // O(1)
    void del(int i)
    {
        table[i] = 0;
    }

    // O(1)
    int search(int i)
    {
        return table[i];
    }
};

int main()
{
    DirectAddressTable dat;

    dat.insert(10);
    dat.insert(20);
    dat.insert(119);
    cout << dat.search(10) << endl;
    cout << dat.search(20) << endl;
    dat.del(119);
    cout << dat.search(119) << endl;

    return 0;
}
