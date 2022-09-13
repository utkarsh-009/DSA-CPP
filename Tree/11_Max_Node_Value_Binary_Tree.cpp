/*
  10
 / \
5  20
   / \
  30  6

O/P: 30
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

//  Recursive [TC: O(n), AS: O(h)]
int getMaxRecur(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    return max(root->key, max(getMaxRecur(root->left), getMaxRecur(root->right)));
}

// Iterative: Using Level Order Traversal [TC: O(n), AS: O(w)]
int getMaxIter(Node *root)
{
    int max_val = INT_MIN;
    if (root == NULL)
    {
        return max_val;
    }

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        max_val = max(max_val, curr->key);
        q.pop();

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }

        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }

    return max_val;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << getMaxIter(root);
}
