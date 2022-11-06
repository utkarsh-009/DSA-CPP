/*
Detection of a Cycle in an Directed Graph using DFS.
Cycle Detection Test in Directed Graph =>
    While calling DFS recursievly, if there is a descendant calling to one of the ancestor in recursion tree.
    This is known as Back Edge, i.e. recursion tree having back edge.

I/P:
    0->1,
    1->2, 1->3,
    2->3, 2->4,
    4->5
O/P: Cycle Found (1->2->3->1)
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]

bool DFSRec(vector<int> adj[], int source, vector<bool> visited, vector<bool> recStack)
{
    visited[source] = true;
    recStack[source] = true; // Maintaining track of recursion stack

    for (int v : adj[s])
    {
        if (visited[v] == false)
        {
            if (DFSRec(adj, source, visited, recStack) == true)
            {
                return true;
            }
        }
        else if (recStack[u] == true)
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

int main()
{
}
