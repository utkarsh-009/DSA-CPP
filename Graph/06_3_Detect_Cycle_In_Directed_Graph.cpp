/*
Detection of a Cycle in an Undirected Graph using Kahn's algorithm (Decreasing indegree of )
- As Kahn's algorithm is only valid for acyclic directed graph
- If this algorithm is cyclic directed graph, then at some moment queue will
  become empty as there will be no vertices with indegree equal to 0

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

//  [TC: ]
bool topologicalSort(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);

    // Counting indegree of every vertices
    for (int u = 0; u < V; u++)
    {
        for (int x : adj[u])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int u = 0; u < V; u++)
    {
        if (indegree[u] == 0)
        {
            q.push(u);
        }
    }

    int count = 0; // No of vertices
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for (int x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }

        count++;
    }

    return (count != V);
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

    if (topologicalSort(adj, V) == true)
        cout << "Cycle found";
    else
        cout << "No cycle found";

    return 0;
}
