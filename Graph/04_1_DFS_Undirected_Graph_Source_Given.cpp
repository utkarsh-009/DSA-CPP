/*
Given an undirected graph and a source vertex 's' ,print D.F.S. from given source

    I/P: Graph: 0->2,1 , 2 ->3,4
    O/P: 0 2 3 4 1
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V+E)
void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRec(adj, u, visited); // Recursievly calling DFS for unvisited node
        }
    }
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    DFSRec(adj, s, visited); // Source is given
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    cout << "Following is Depth First Traversal: " << endl;
    DFS(adj, V, 0);

    return 0;
}