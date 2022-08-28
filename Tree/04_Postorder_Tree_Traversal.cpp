/*
Postorder Traversal: LEFT RIGHT ROOT

  10
 / \
5  20
   / \
  30  6

Postorder Traversal: 5 30 6 20 10

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

void postorderTrav(Node *root)
{
    if (root != NULL)
    {
        postorderTrav(root->left);
        postorderTrav(root->right);
        cout << root->key << " ";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    postorderTrav(root);
}