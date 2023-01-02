/*
Optimising Prims Algorithm using Priority Queue and Adjacency List Representation
*/

#include <bits/stdc++.h>
using namespace std;

// Prims Optimised Algorithm [TC: ,AS:]
int primsMSTOptimised(vector<int> adj[])
{
    vector<int> key(V, INT_MAX);
    int res = 0;

    vector<bool> mSet(V, false);
    
}

// Adding edge with given weight
void addEdge(vector<int> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
int main()
{
    vector<vector<pair<int, int>>> adj(V);
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    cout << primMST(adj);
}
