#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

// Adjacency List Node Class: Contains getV(), getWeight() functions
class AdjListNode
{
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};

// Graph Class: Contains topologicalSortUtil(), addEdge(), shortestPath() functions
class Graph
{
    int V;

    list<AdjListNode> *adj;

    void topologicalSortUtil(int v, vector<bool> visited, stack<int> &Stack);

public:
    Graph(int V);

    void addEdge(int u, int v, int weight);

    void shortestPath(int s);
};

// Graph constructor
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

// Add Edge Function
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

// Topological Sort
void Graph::topologicalSortUtil(int v, vector<bool> visited, stack<int> &Stack)
{

    visited[v] = true;

    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (visited[node.getV()] == false)
            topologicalSortUtil(node.getV(), visited, Stack);
    }

    Stack.push(v);
}

/*
Shortest Path in DAG
- Keeping track of minimum distance array, dist[V] = {INF, INF,...} and making sources s as dist[s] = 0
- Finding Topological Sort: We find topological sort because we go to source to all the other node in forward direction, i.e.
    we will never have a edge which is going from forward to backward direction.
- Using Relaxation Operation, we find shortest path between node and source
    Relaxation Operation: if(d[v] > d[u] + w(u,v)) => d[v] = d[u] + w(u,v)

Example =>
        I/P: 0->1 (1)
         1->2 (3), 1->3 (2)
         2->3 (4)
        source = 1
        O/P: 1, 0, 3, 2
*/

// Shortest Path function [TC: O(V+E)]
void Graph::shortestPath(int s)
{
    stack<int> Stack;

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // Keeping track of minimum distance array, dist[V] = {INF, INF,...} and making sources s as dist[s] = 0
    vector<int> dist(V, INF);
    dist[s] = 0;

    // Using BFS
    while (Stack.empty() == false)
    {
        int u = Stack.top();
        Stack.pop();

        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                // Relaxation Operation
                if (dist[i->getV()] > dist[u] + i->getWeight())
                {
                    dist[i->getV()] = dist[u] + i->getWeight();
                }
            }
        }
    }

    // Shortest Path in DAG
    for (int i = 0; i < V; i++)
        (dist[i] == INF) ? cout << "INF " : cout << dist[i] << " ";
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 2, 2);
    g.addEdge(4, 5, 4);
    g.addEdge(2, 3, 6);
    g.addEdge(5, 3, 1);

    int s = 0;
    cout << "Following are shortest distances from source " << s << " \n";
    g.shortestPath(s);

    return 0;
}
