/*
Preorder Traversal: ROOT LEFT RIGHT

  10
 / \
5  20
   / \
  30  6

Preorder Traversal: 10 5 20 30 6

TC: O(n), AS: O(h)
*/

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

void preorderTrav(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorderTrav(root->left);
        preorderTrav(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    preorderTrav(root);
}