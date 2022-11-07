/*
Detection of a Cycle in an Directed Graph using DFS.
Cycle Detection Test in Directed Graph =>
    While calling DFS recursievly, if there is a descendant calling to one of the ancestor in recursion tree.
    This is known as Back Edge, i.e. recursion tree having back edge.

I/P:
    0->1,
    2->1, 2->3,
    3->4,
    4->5,
    5->3
O/P: Cycle Found (3->4->5->3)
*/

#include <bits/stdc++.h>
using namespace std;

// Maintaining a recursion call stack for checking cycle [TC: O(V+E)]
bool DFSRec(vector<int> adj[], int source, vector<bool> visited, vector<bool> recStack)
{
    visited[source] = true;
    recStack[source] = true; // Maintaining track of recursion stack

    for (int u : adj[source])
    {
        if (visited[u] == false)
        {
            if (DFSRec(adj, u, visited, recStack) == true) // Back Edge found
            {
                return true;
            }
        }
        else if (recStack[u] == true) // Descendant calling to one of the ancestor in recursion stack
        {
            return true;
        }
    }

    // Marking recStack[source] as false because the source vertex is out of recusion call stack
    recStack[source] = false;

    return false;
}

bool DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);  // All nodes unvisited initially
    vector<bool> recStack(V, false); // To maintain track of recursion call stack

    for (int i = 0; i < V; i++) // To handle the disconnected graph case
    {
        if (visited[i] == false)
        {
            if (DFSRec(adj, i, visited, recStack) == true) // if Cycle Detected
            {
                return true;
            }
        }
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if (DFS(adj, V) == true)
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
