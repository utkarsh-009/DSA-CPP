/*
Given an undirected graph and source vertex not given ,print B.F.S.
Note: Graph May be Disconnected
*/

#include <bits/stdc++.h>
using namespace std;

//  Using Queue [TC: O(V+E)]
void BFS(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// BFS when source is not given and graph nodes are disconnected [TC: O(V+E)]
// Intution: When Graph Nodes are disconnected then we will call BFS for every non-visited node.
void BFSdis(vector<int> adj[], int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false) // Calling BFS for every non-visited node
        {
            BFS(adj, i, visited);
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);

    cout << "Following is Breadth First Traversal: " << endl;
    BFSdis(adj, V);

    return 0;
}
