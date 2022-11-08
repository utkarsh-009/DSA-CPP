/*
    I/P:
    0 5 10 0
    5 0 3 20
    10 3 0 2
    0 20 2 0
    src = 0
    O/P: dist[] = {0,5,8,10}

    I/P:
    0 5 3
    5 0 1
    3 1 0
    src = 1
    O/P:dist[] = {4,0,1}
*/
#include <bits/stdc++.h>
using namespace std;
#define V 4

/*
Dijkstra’s Algorithm: To Find Shortest Path from the Source to all Vertices
- Create a set finalised set 'fin', that keeps track of vertices included in the shortest-path tree,
  i.e., whose minimum distance from the source is calculated and finalized. Initially, this set is empty.
- Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE.
  Assign the distance value as 0 for the source vertex so that it is picked first.
- While fin set doesn’t include all vertices
    -> Pick a vertex u which is not there in fin set and has a minimum distance value.
    -> Include u to fin set.
    -> Then update distance value of all adjacent vertices of u.
    -> To update the distance values, iterate through all adjacent vertices.
    -> For every adjacent vertex v, if the sum of the distance value of u (from source) and weight of edge u-v,
       is less than the distance value of v, then update the distance value of v.
- Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree.
- Using Priority Queue and Adjacency Matrix, the Algorithm can be optimisied to O(ElogV)

NOTE: Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. It may give correct results for a graph
with negative edges but you must allow a vertex can be visited multiple times and that version will lose its fast time complexity.
For graphs with negative weight edges and cycles, the Bellman-Ford algorithm can be used.
*/

// Dijkstra’s Algorithm [TC: O(V*V)]
vector<int> djikstra(int graph[V][V], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // To  keeps track of vertices whose minimum distance from the source is calculated and finalized.
    vector<bool> fin(V, false);

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            // Updating u when, ith vertex is not finalised and either u value is -1 or dist[i] < dist[u]
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        fin[u] = true; // vertex finalised
        for (int v = 0; v < V; v++)
        {
            // Relaxation Operation
            if (graph[u][v] != 0 && fin[v] == false)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    return dist;
}

int main()
{
    int graph[V][V] = {
        {0, 50, 100, 0},
        {50, 0, 30, 200},
        {100, 30, 0, 20},
        {0, 200, 20, 0},
    };

    for (int x : djikstra(graph, 0))
    {
        cout << x << " ";
    }

    return 0;
}
