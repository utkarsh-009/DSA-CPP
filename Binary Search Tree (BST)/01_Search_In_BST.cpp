/*
Given root and the key, check whether key is present in the BST or not.
    I/P: Root Given, Key Given
    O/P: True/ False
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

// Recursive [TC: O(h),AS: O(h)]
bool searchRecur(Node *root, int x)
{
    // Base Case
    if (root == NULL) // Empty Binary Search Tree
    {
        return false;
    }

    else if (root->key == x) // Key found
    {
        return true;
    }

    else if (root->key > x) // Search in left subtree
    {
        return searchRecur(root->left, x);
    }

    else // Search in right subtree
    {
        return searchRecur(root->right, x);
    }
}

// Iteratives [TC: O(h), AS: O(1)]
bool searchIter(Node *root, int x)
{
    while (root != NULL) // Base Case
    {
        if (root->key == x) // Key found
        {
            return true;
        }
        else if (root->key > x) // Search in left subtree
        {
            root = root->left;
        }
        else // Search in right subtree
        {
            root = root->right;
        }
    }

    return false;
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
    int x = 16;

    if (searchIter(root, x))
        cout << "Found";
    else
        cout << "Not Found";
}
