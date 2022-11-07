/*
Topological Sorting Using Kahn's BFS Based Algortihm
- The topological sort algorithm takes a directed graph and
  returns an array of the nodes where each node appears before all the nodes it points to.
- We will store indegree of every vertex.
- Then add all 0 indegree vertices to the q.
- Now for every adjacent v of u,
    reduce the indegree of v by 1 and if indegree of v becomes 0 => Add it into queue

    I/P: 0->1, 0->2
    O/P: 0 1 2 or 0 2 1

    I/P: 0->2,0->3
         1->3, 1->4
    O/P: 0 1 2 3 4 or 1 0 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

// Topological Sorting Using BFS [TC: O(V+E)]
void topologicalSort(vector<int> adj[], int V)
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

    // Adding all vertices having 0 indegree
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Using BFS
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        cout << u << " ";
        for (int x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    cout << "Following is a Topological Sort of\n";
    topologicalSort(adj, V);

    return 0;
}
