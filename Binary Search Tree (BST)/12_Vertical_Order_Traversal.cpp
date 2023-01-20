/*
Given a binary search tree, find vertical traversal
Intution: Using Queue of pair<Node*, int> we store node and its horizontal distance.
This helps us in finding vertical traversal with node from top to bottom.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

// M1: [TC: O(N), AS: O(N)]
void verticalTraversal(Node *root)
{
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false)
    {
        Node *node = q.front().first;
        int hd = q.front().second;
        q.pop();

        mp[hd].push_back(node->key);

        if (node->left != NULL)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto hd : mp)
    {
        for (int x : hd.second)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    verticalTraversal(root);

    return 0;
}