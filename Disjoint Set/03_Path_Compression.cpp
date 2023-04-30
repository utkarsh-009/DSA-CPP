/*
We optimise upcoming find operations using Path Compression.
Advantage: It reduces height of tree.
*/

/*
Time Complexity (Union by Rank and Path Compression):
For m operations it takes O(m*alpha(n)) time => On average it takes O(1) for single operation as alpha(n) i.e. Inverse Ackerman Function takes constant time
*/
#include <bits/stdc++.h>
using namespace std;
#define n 5

class DSU
{
private:
    int parent[n];
    int rank[n];

public:
    DSU()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Path Compression
    int find(int x)
    {
        if (parent[x] == x)
            return x;

        /*
         we make parent of x to x's representative i.e. connecting the x to root directly
        which reduces height of tree. This will reduce upcoming operations cost
        */
        parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by Rank
    void union(int x, int y)
    {
        int x_rep = find(x), y_rep = find(y);
        // if x_rep's rank greater than y_rep's rank then we set parent of y_rep as x_rep
        if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        // if y_rep's rank greater than x_rep's rank then we set parent of x_rep as y_rep
        else if (rank[x_rep] < rank[y_rep])
            parent[x_rep] = y_rep;
        // we can make anyone's representative as anyone's parent but for convention we make y_rep's parent as x_rep
        else
        {
            parent[y_rep] = x_rep;
            // NOTE: that as both of them have same height. Hence, when we make y_rep parent as x_rep, the height increases by 1 => increase rank of x_rep by 1.
            rank[x_rep]++;
        }
    }
};