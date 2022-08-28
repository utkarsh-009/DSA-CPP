/*
Inorder Traversal: LEFT ROOT RIGHT

  10
 / \
5  20
   / \
  30  6

Inorder Traversal: 5 10 30 20 6

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

void inorderTrav(Node *root)
{
    if (root != NULL)
    {
        inorderTrav(root->left);
        cout << (root->key) << " ";
        inorderTrav(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    inorderTrav(root);
}