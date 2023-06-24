/*
- The Spanning Tree is a tree which does no have any cycle and it should be connecting all the vertices. If V edges => (V-1) edges
- The cost of the Minimum Spanning Tree is the minimum sum of the weights of all the edges in the tree.

    I/P:
    graph[][] =
    0 5 8 0
    5 0 10 0
    8 10 0 20
    0 15 20 0
    O/P: 28 (5 + 8 + 15)

    I/P:
    graph[][] =
    0 2 0 6 0
    2 0 3 8 5
    0 3 0 0 7
    6 8 0 0 9
    0 5 7 9 0
    O/P: 16 (6 + 2 + 5 + 3)

*/

#include <bits/stdc++.h>
using namespace std;
#define V 4

/*
Prim's Algorithm: To find MST.
Intuition: The algorithm starts from a given vertex and greedily expands the tree by adding the minimum weight edge at each step.
- Use a boolean array mstSet[] to track the inclusion of vertices in the MST.
- Array key[] is used to store and keep track of the minimum weight edge connecting each vertex to the current Minimum Spanning Tree.
- Another array parent[] to store indexes of parent nodes in MST. The parent array is the output array, which is used to show the constructed MST.
*/

// Prim's Algorithm [TC: O(V*V)]
int primMST(int graph[V][V])
{
    vector<int> key(V, INT_MAX);
    int res = 0;

    vector<bool> mSet(V, false); // To keep track the of vertices included in MST.
    key[0] = 0;                  // starting vertex

    // The MST will have V vertices. Hence, we iterate V times to add V-1 edges to the MST.
    for (int count = 0; count < V; count++)
    {
        int u = -1; // to store the minimum key value among the vertices not yet included in the MST

        // Picking minimum key vertex from the set of vertices not yet included in MST. (NOTE: In first iteration we will always pick vertex)
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mSet[u] = true; // Mark it as Included
        res += key[u];  // Add Key value to result

        /*
        As new node is already added to tree => We update the key array.
        Iterate over all vertices v that are not yet included in the MST and update the key value of v if the weight of the
        edge (graph[u][v]) is smaller than the current key value of v.
        */
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] != 0 => edge exists between u and v. mSet[v] = false => The vertex is not included in mst set
            if (graph[u][v] != 0 && mSet[v] == false)
            {
                // Updates key values for next iteration. The minimum key will be picked in next iteration
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }

    return res;
}

int main()
{
    int graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    cout << primMST(graph);

    return 0;
}
