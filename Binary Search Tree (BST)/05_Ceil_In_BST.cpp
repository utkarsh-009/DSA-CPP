/*
We need to find Ceil of given value in BST. Floor is the closest greater or equal to value.
If no such value present we return -1.
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

int BSTCeil(Node *root, int x)
{
    int ceil = -1;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->key == x)
        {
            return x;
        }
        else if (curr->key < x)
        {
            curr = curr->right;
        }
        else
        {
            ceil = curr->key;
            curr = curr->left;
        }
    }

    return ceil;
}

int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int x = 17;

    cout << "Ceil: " << BSTCeil(root, 17);
}
