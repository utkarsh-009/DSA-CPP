/*
Optimising Prims Algorithm using Priority Queue and Adjacency List Representation

- Using Priority Queue and Adjacency List Representation,
    The time complexity of algorithm becomes O(VlogV + (V+E)logV) => O((V+E)logV)
NOTE: In connected graph, the minimum number of edges are atleast (V-1) and
maximum number of edges can go upto V*(V-1)/2 => V = O(E)

- parent array is used to store MST
*/

#include <bits/stdc++.h>
using namespace std;

// Prims Optimised Algorithm [TC: O(ElogV)]
void primsMSTOptimised(vector<pair<int, int>> adj[], int V)
{
    vector<int> key(V, INT_MAX);
    int res = 0;

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    vector<bool> mSet(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap for pair<int,int>

    // Insert source vertex into pq and make its key as 0
    int src = 0; // source is 0
    pq.push({0, src});
    key[src] = 0;

    while (pq.empty() == false)
    {
        // int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (mSet[u] == true)
        {
            continue;
        }

        mSet[u] = true;
        res += key[u];

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (mSet[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "MST Using Prims Algorithm is: " << endl;

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }

    cout << "\nCost of MST Using Prims Algorithm is: " << res;
}

// Adding edge with given weight
void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
int main()
{
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
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

    primsMSTOptimised(adj, V);
}
