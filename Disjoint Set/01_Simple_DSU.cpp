/*
DSU has two important operations: find and union
Intution:
- We maintain a parent[] which is equal to size of elements. It stores parent/representative of node itself.
- In union(a,b), we make b as child of a
- In find(x), we check if it is root node, as parent[x] == x for root node. Also, if not then we recursievly call
    find(parent[x])
*/

// [TC: O(N), AS: O(N)]
#include <bits/stdc++.h>
using namespace std;
#define n 5

class SimpleDSU
{
private:
    int parent[5];

public:
    SimpleDSU()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find: returns representative of x's set
    int find(int x)
    {
        // if it is root node => parent[x] = x
        if (parent[x] == x)
            return x;
        // if not then we recursievly call find(parent[x])
        else
            return find(parent[x]);
    }

    // Union: Combines sets of x and y
    void unions(int x, int y)
    {
        // finding representative of x and y
        int x_rep = find(x);
        int y_rep = find(y);

        // if they have same => return
        if (x_rep == y_rep)
            return;

        // Else we make parent of y's representative as x's representative
        parent[y_rep] = x_rep;
    }
};

int main()
{
    SimpleDSU dsu;

    dsu.unions(0, 2);
    dsu.unions(0, 4);

    cout << dsu.find(4) << endl;
    cout << dsu.find(3) << endl;
}
