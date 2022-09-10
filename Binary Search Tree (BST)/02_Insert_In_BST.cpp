/*
To insert a node in a BST.
NOTE: if the key is already present in the BST then we do nothing.
    I/P: x = 20
    O/P: Insert 20 at right position in BST
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

/*
We first search for the key and if the key is not present in the BST then we insert the key with the leaf node.
Else if the key is already present in the BST then we do nothing.
*/

// Recursive [TC: O(h), AS: O(h)]
Node *insertRecur(Node *root, int x)
{
    // Base Case
    if (root == NULL)
    {
        return new Node(x); // New node allocation on leaf node
    }

    // NOTE: if node with value key is already present in BST then, the right and left pointer just gets overriden
    else if (root->key > x)
    {
        root->left = insertRecur(root->left, x); // We store recursive call in root->left, inorder to link the new node and current leaf node
    }

    else
    {
        root->right = insertRecur(root->right, x); // We store recursive call in root->right, inorder to link the new node and current leaf node
    }

    return root;
}

//  Iterative [TC: O(h), AS: O(1)]
Node *insertIter(Node *root, int x)
{
    Node *temp = new Node(x);
    // We need to have hold of parent node along with current node: As we need to insert node at parent's left/right when curr is NULL.
    Node *parent = NULL, *curr = root;

    while (curr != NULL)
    {
        parent = curr; // Storing curr pointer to parent

        // For moving curr to ideal position for insertion at parent's left/right
        if (curr->key > x)
        {
            curr = curr->left;
        }
        else if (curr->key < x)
        {
            curr = curr->right;
        }

        else // Case when node is already present in BST
        {
            return root;
        }
    }
    if (parent == NULL) // Empty BST
    {
        return temp;
    }

    // Inserting to parent's left/right
    if (parent->key > x)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 20;

    root = insertIter(root, x);
    inorder(root);
}
