/*
Topological Sorting Using DFS
- The topological sort algorithm takes a directed graph and
  returns an array of the nodes where each node appears before all the nodes it points to.
- Create a empty stack.
- For every vertex u, we recursievly call DFS(u, st).
- Again calling DFS recursively for unvisited node v, where v is adjacent of u.
- Then, pushing the v node into stack, where v does not have adjacent unvisited node.
- Stack will have nodes stored in topologically sorted order.

    I/P: 0->1, 0->2
    O/P: 0 1 2 or 0 2 1

    I/P: 0->2,0->3
         1->3, 1->4
    O/P: 0 1 2 3 4 or 1 0 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

// Topological Sorting Using DFS [TC: O(V+E)]
void DFS(vector<int> adj[], int u, stack<int> &st, vector<bool> &visited)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v] == false) // Calling DFS recursively for unvisited node v, where v is adjacent of u.
        {
            DFS(adj, v, st, visited);
        }
    }

    st.push(u); // Pushing the v node into stack, where v does not have adjacent unvisited node.
}

void topologicalSort(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    stack<int> st;

    // For every vertex u, we recursievly call DFS(u, st).
    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            DFS(adj, u, st, visited);
        }
    }

    // The Stack will contain vertices with highest indegrees at top of stack.
    while (st.empty() == false)
    {
        int u = st.top();
        st.pop();

        cout << u << " ";
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
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 4);

    cout << "Following is a Topological Sort of\n";
    topologicalSort(adj, V);

    return 0;
}
