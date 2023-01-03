/*
    I/P: Adjacency List with format (u,v,w) => Edge u-v with weight w
    O/P: Shortest Path from Source to all other vertex

*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

// Djikstra Opitimised Using Adjacency List and Priority Queue (Min Heap) [TC: O(ElogV)]
vector<int> djikstraOptimised(vector<iPair> adj[], int src, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push({0, src});

    while (pq.empty() == false)
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

void addEdge(vector<iPair> adj[], int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int main()
{
    int V = 9;
    vector<iPair> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    for (int x : djikstraOptimised(adj, 0, V))
    {
        cout << x << " ";
    }
}
