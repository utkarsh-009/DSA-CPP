/*
Height of Tree

  10
 / \
5  20
   / \
  30  6

O/P: 3 (i.e. 10->20->30 or 10->20->6)

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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << "Height of given Tree is: " << height(root);
}