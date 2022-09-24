/*
  10
 / \
5  20
   / \
  30  6
O/P:
    10
   / \
  20  5
 / \
6 30
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

//  [TC: ,AS:]

// Iterative [TC: ,AS: ]
void mirror(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        swap(curr->left, curr->right);
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

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(15);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << "\n Inorder traversal of the constructed tree is \n";
    inOrder(root);

    /* Convert tree to its mirror */
    mirror(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\n Inorder traversal of the mirror tree is \n";
    inOrder(root);
}
