/*
    I/P:
    O/P:

    I/P:
    O/P:
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
class Graph
{
private:
    bool **adjMatrix;   // Using boolean matrix as adjacency matrix
    int no_of_vertices; // No of vertices present in adjacency matrix

public:
    // Constructor to initialise the no of vertices and setting adjacency matrix initially to false
    Graph(int no_of_vertices)
    {
        this->no_of_vertices = no_of_vertices;
        adjMatrix = new bool *[no_of_vertices]; // dynamically allocating size of array of boolean-array type pointers
        for (int i = 0; i < no_of_vertices; i++)
        {
            adjMatrix[i] = new bool[no_of_vertices]; // dynamically allocating size of every element of boolean-array type pointer
            for (int j = 0; j < no_of_vertices; j++)
            {
                adjMatrix[i][j] = false; // initialising it as false
            }
        }
    }
    // Operations for Undirected Graph

    //  Add edges: [TC: O(1)]
    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove edges: [TC: O(1)]
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    // Print the matrix [TC: O(V*V)]
    void toString()
    {
        for (int i = 0; i < no_of_vertices; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < no_of_vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Before Remove Edge 1,2: " << endl;
    g.toString();
    cout << "After Remove Edge 1,2: " << endl;
    g.removeEdge(1, 2);

    g.toString();
}
