/*
Vertically Traversing through all nodes
     10
    / \
   5  20
      / \
     30  35
O/P: 5
     10 30
     20
     35
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *right;
    Node *left;

    Node(int k)
    {
        key = k;
        right = left = NULL;
    }
};

// Using Level Order Traversal [TC: O(n), AS: O(n)]
void printVerticalOrderTraversal(Node *root)
{
    // Map is used to store vertical order
    if (root == NULL)
    {
        return;
    }

    map<int, vector<int>> mp; // Create a map to store vertical order in map, map<Horizontal Distance, Node Values> mp
    int hd = 0;               // Initialising Horizontal Distance as 0

    queue<pair<Node *, int>> q;  // Node and horizontal distance
    q.push(make_pair(root, hd)); // Initially pushing root node and horizontal distance 0

    // Level Order Traversal and Storing node values inside map using horizontal distance as key
    while (q.empty() == false)
    {
        pair<Node *, int> curr = q.front(); // Node and Horizontal Distance
        q.pop();
        hd = curr.second;
        Node *node = curr.first;

        mp[hd].push_back(node->key); // Storing node values inside map using horizontal distance as key

        if (node->left != NULL) // For Left child hd = hd - 1
        {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right != NULL) // For Right Child hd = hd + 1
        {
            q.push(make_pair(node->right, hd + 1));
        }
    }

    map<int, vector<int>>::iterator it;         // Map iterator
    for (it = mp.begin(); it != mp.end(); it++) // Printing vector for every horizontal distance
    {
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    printVerticalOrderTraversal(root);
}
