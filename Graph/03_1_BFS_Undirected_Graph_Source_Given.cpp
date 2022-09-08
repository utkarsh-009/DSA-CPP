/*
Given an undirected graph and a source vertex 's' ,print B.F.S. from given source

    I/P: Graph: 0->1,2 , 2 ->3,4
    O/P: 0 1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

// Using Queue [TC: O(V+E)]
void BFS(vector<int> adj[], int V, int s)
{
    bool visited[V]; // To keep track of all visited vertices
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    // Source
    visited[s] = true;
    q.push(s);

    while (q.empty() == false) // BFS Traversal Using Queue
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true; // Marking the vertex as visited
                q.push(v);
            }
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

    int V = 5, s = 0;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Breadth First Traversal: " << endl;
    BFS(adj, V, s);
}
