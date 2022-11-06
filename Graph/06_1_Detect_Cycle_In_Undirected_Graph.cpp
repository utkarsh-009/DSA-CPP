/*
Detection of a Cycle in an Undirected Graph.
Cycle Detection Test for Undirected Graph =>
    1.) Adjacent of a node is visited
    2.) The adjacent node is not parent of current node

I/P:
    0<->1,
    1<->2, 1<->3,
    2<->3, 2<->4,
    4<->5
O/P: Cycle Found (1->2->3->1)
*/

#include <bits/stdc++.h>
using namespace std;

// Maintaining a parent variable for checking cycle [TC: O(V+E)]
bool DFSRec(vector<int> adj[], int source, vector<bool> visited, int parent)
{
    visited[source] = true;

    for (int u : adj[source])
    {
        if (visited[u] == false) // current node is not visited
        {
            if (DFSRec(adj, u, visited, source) == true) // recursievly calling dfs to visit adjacent nodes
            {
                return true;
            }
        }
        else if (u != parent) // Adjacent of current node that is visited and is not parent of current node => Cycle Detected
        {
            return true;
        }
    }

    return false; // No cycle detected
}

// Using DFS
bool DFSDetectCycle(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) // To handle the disconnected graph case
    {
        if (visited[i] == false)
        {
            if (DFSRec(adj, i, visited, -1) == true) // if Cycle Detected
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
    adj[v].push_back(u);
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    if (DFSDetectCycle(adj, V))
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
