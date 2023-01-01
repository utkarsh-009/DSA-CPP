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
- Use a boolean array mstSet[] to represent the set of vertices included in MST.
  If a value mstSet[v] is true, then vertex v is included in MST, otherwise not.
- Array key[] is used to store key values of all vertices. Another array parent[] to store indexes of parent nodes in MST.
- The parent array is the output array, which is used to show the constructed MST.
- Using Priority Queue, the Algorithm can be optimisied to O(ElogV)
*/

// Prim's Algorithm [TC: O(V*V)]
int primMST(int graph[V][V])
{
    vector<int> key(V, INT_MAX);
    int res = 0;

    vector<bool> mSet(V, false); // To keep track the of vertices included in MST.
    key[0] = 0;

    // The MST will have V vertices
    for (int count = 0; count < V; count++)

    {
        int u = -1;
        for (int i = 0; i < V; i++) // Picking minimum key vertex from the set of vertices not yet included in MST
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mSet[u] = true; // Mark it as Included
        res += key[u];  // Add Key value to result

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && mSet[v] == false) // Updating key value of adjacent vertices
            {
                key[v] = min(key[v], graph[u][v]); // To get minimum edge value
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
