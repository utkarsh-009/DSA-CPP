/*
Maximum Width of Binary tree is the maximum number of nodes present in a level of the Tree.
    10
    / \
   5  20
  /   / \
 15  30  6

O/P: 3
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

// Using Level Order Traversal [TC: O(n), AS: O(w)]
int maxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int max_width = 0;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int width = q.size();

        max_width = max(max_width, width);
        for (int i = 0; i < width; i++)
        {
            Node *curr = q.front();
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
    }

    return max_width;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(15);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << maxWidth(root);
}
