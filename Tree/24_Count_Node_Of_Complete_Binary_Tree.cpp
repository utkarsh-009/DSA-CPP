/*
A complete binary tree is a binary tree in which every level, except possibly the last,
is completely filled, and all nodes in the last level are as far left as possible.

      10
     / \
    5  20
   / \
  30  6

O/P: 5
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

//  [TC: O(n), AS: O(h)]
int countNodeNaive(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + countNodeNaive(root->left) + countNodeNaive(root->right);
}

//  [TC: O(logn*logn), AS: O(logn)]
int countNodeEff(Node *root)
{

    if (root == NULL)
        return 0;

    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }

    // Full Binary Tree
    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    // Recursievly call for left subtree and right subtree
    else
    {
        return 1 + countNodeEff(root->left) + countNodeEff(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << countNodeEff(root);
}
