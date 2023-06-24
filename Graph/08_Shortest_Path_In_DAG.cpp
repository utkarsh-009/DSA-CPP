#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

/*
Shortest Path in DAG
- Keeping track of minimum distance array, dist[V] = {INF, INF,...} and making sources s as dist[s] = 0
- Finding Topological Sort: We find topological sort because we go to source to all the other node in forward direction, i.e.
    we will never have a edge which is going from forward to backward direction.
- Using Relaxation Operation, we find shortest path between node and source
    Relaxation Operation: if(d[v] > d[u] + w(u,v)) => d[v] = d[u] + w(u,v)

Example =>
Input: n = 6, m= 7, edge=[[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output: 0 2 3 6 1 5
*/

// Shortest Path function [TC: O(V+E)]
class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edge)
    {
        // Graph storing u-><v,cost>
        vector<vector<vector<int>>> adj(N);
        vector<int> topoSort;

        for (int i = 0; i < M; i++)
        {
            adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        }

        // Modified Topolgical Sort used. As source is only 0. Hence, we will push all the adjacents starting from src 0.
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            topoSort.push_back(u);
            q.pop();

            for (auto e : adj[u])
            {
                int v = e[0];
                q.push(v);
            }
        }

        // Initially store INF
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        for (int i = 0; i < topoSort.size(); i++)
        {
            int u = topoSort[i];
            for (auto e : adj[u])
            {
                int v = e[0];
                int cost = e[1];
                if (dist[v] > dist[u] + cost)
                {
                    dist[v] = dist[u] + cost;
                }
            }
        }

        return dist;
    }
};

int main()
{
    int n = 6, m = 7;
    vector<vector<int>> edges{
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};

    Solution obj;
    vector<int> res = obj.shortestPath(n, m, edges);
    for (auto x : res)
    {
        cout << x << " ";
    }
}
