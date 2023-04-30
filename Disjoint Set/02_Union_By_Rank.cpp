/*
Intution: We use ranks to decide which element is going to become child of which element.
The ranks are basically the height of tree. We make smaller height node's representative as
child of the higher height node's representative
*/

/*
Time Complexity: For m operations it takes O(mlogn) time => On average it takes O(logn) for single operation
*/
#include <bits/stdc++.h>
using namespace std;
#define n 5

class DSU_By_Rank
{
private:
    int parent[n];
    int rank[n];

public:
    DSU_By_Rank()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return find(parent[x]);
    }

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