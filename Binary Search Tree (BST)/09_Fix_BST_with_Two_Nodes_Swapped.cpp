/*
Given a binary search tree with two swapped nodes, the task is to fix the binary search tree by swapping them back.

There wll be two cases:
C1: With 1 violation
C2: With 2 violation

-> previous, first, second variable is initialised to NULL.
-> Using inorder traversal, we will check for element whose previous is greater than current and assign first to var(previous)
and second to current.
-> Now if we find another violation, then first variable is not NULL => We just assign current to second.
-> Now swapping first and second will give us fixed BST.
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

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// M1(Efficient): [TC: O(n), AS: O(n)]
Node *previous = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    fixBST(root->left);

    if (previous != NULL && root->key < previous->key)
    {
        if (first == NULL)
        {
            first = previous;
        }
        second = root;
    }

    previous = root;
    fixBST(root->right);
}

int main()
{
    Node *root = new Node(18);
    root->left = new Node(60);
    root->right = new Node(70);
    root->left->left = new Node(4);
    root->right->left = new Node(8);
    root->right->right = new Node(80);

    inorder(root);
    cout << endl;
    fixBST(root);
    int temp = first->key;
    first->key = second->key;
    second->key = temp;
    inorder(root);

    return 0;
}