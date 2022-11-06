/*
Given an Unweighted Graph and a source point,
the task is to find the shortest path between the source point and every other point in the graph.

I/P:
    0->1, 0->2
    1->2, 1->3
    2->3
O/P: 0 1 1 2
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(V+E)]
void BFS(vector<int> adj[], int V, int source, int dist[])
{
    vector<bool> visited(V, false); // To keep track of visited nodes
    queue<int> q;

    // initially marking source as visited and pushing it into queue
    visited[source] = true;
    q.push(source);

    // Using BFS and updating dist[]
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;

                q.push(v);
            }
        }
    }
}

// To add edge into graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    BFS(adj, V, 0, dist);

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}
