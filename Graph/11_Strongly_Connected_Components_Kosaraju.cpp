/*
    I/P:
        0-> 2
        1-> 0
        2-> 1, 3
        3-> 4
        4-> 3
    O/P: 0 1 2
         3 4

- Kosaraju's Algorithm is used to find Strongly Connected Components.
- Strongly Connected Components: Set of vertices that forms connection is such a way that every pair is reachable from each other.
- Kosaraju's Algorithm:
    -> Step1: Order the vertices in decreasing order of their finish time in DFS
    -> Step2: Reverse all the edges
    -> Step3: Now do DFS of the reversed adj in the order obtained in Step1.
        For every vertex print all the reachable vertices as the strongly connected component.
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]

void DFS(int u, vector<int> reversed_adj[], vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";

    for (int v : reversed_adj[u])
    {
        if (visited[v] == false)
        {
            DFS(v, reversed_adj, visited);
        }
    }
}

void finishTimeOrder(int u, vector<int> adj[], vector<bool> visited, stack<int> &s)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            finishTimeOrder(v, adj, visited, s);
        }
    }

    s.push(u);
}

void getTranspose(int V, vector<int> adj[], vector<int> reversed_adj[])
{

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < adj[u].size(); v++)
        {
            reversed_adj[v].push_back(adj[u][v]);
        }
    }
}

void printSCC(vector<int> adj[], vector<int> reversed_adj[], int V)
{
    stack<int> s;
    vector<bool> visited(V);

    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            finishTimeOrder(u, adj, visited, s);
        }
    }

    getTranspose(V, adj, reversed_adj);

    fill(visited.begin(), visited.end(), false);

    while (s.empty() == false)
    {
        int u = s.top();
        s.pop();

        if (visited[u] == false)
        {
            DFS(u, reversed_adj, visited);
            cout << endl;
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
    vector<int> reversed_adj[V];

    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);

    printSCC(adj, reversed_adj, V);
}
