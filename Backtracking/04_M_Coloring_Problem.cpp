/*
Input: N = 4, M = 3, E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the given graph using 3 colours.
*/

// [Time Complexity: O(M^N), Auxiliary Space: O(N)]
bool isSafe(bool graph[101][101], vector<int> &color, int n, int src, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[src][i] == 1 && color[i] == c)
        {
            return false;
        }
    }

    return true;
}

bool dfs(bool graph[101][101], int m, int n, vector<int> &color, int src)
{
    if (src == n)
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, color, n, src, c))
        {
            color[src] = c;
            if (dfs(graph, m, n, color, src + 1))
            {
                return true;
            }
            color[src] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    return dfs(graph, m, n, color, 0);
}