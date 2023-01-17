/*
Three types of deletetion:
C1: When node to be deleted is leaf node
C2: When node to be deleted has one node empty and one node non-empty
C3: When node to be deleted has both nodes non-empty (Replace it with either lowest or greater value)
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

// *Using Inorder Traversal when right child not empty* (In BST, inorder traversal gives the sorted order)
Node *getSuccessor(Node *curr) // To find closest greater value (LEFTMOST LEAF OF RIGHT SUBTREE OF CURR)
{
    // We move onto the right subtree and go to left pointer unless curr != NULL && curr->left != NULL
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// Reccursive [TC: O(h),AS: O(h)]
Node *delNode(Node *root, int x)
{
    if (root == NULL) // Empty BST
    {
        return root;
    }

    // Recursively going to left/right subtree according to given condition
    if (root->key > x)
    {
        root->left = delNode(root->left, x);
    }

    else if (root->key < x)
    {
        root->right = delNode(root->right, x);
    }

    // Deleting the node
    else
    {
        // Handles both C1 and C2
        if (root->left == NULL) // left child empty
        {
            Node *temp = root->right; // stores right of parent
            delete root;              // delete parent
            return temp;              // return temp to parent caller
        }
        else if (root->right == NULL) // right child empty
        {
            Node *temp = root->left; // stores left of parent
            delete root;             // delete parent
            return temp;             // return temp to parent caller
        }
        // C3 deletion
        else
        {
            Node *succ = getSuccessor(root);               // Finding closest succesor
            root->key = succ->key;                         // Copy succ key to root key
            root->right = delNode(root->right, succ->key); // And recursively delete succ node
        }
    }

    return root;
}

// Printing sInorder Traversal
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
    int x = 15;

    inorder(root);
    cout << endl;
    root = delNode(root, x);
    inorder(root);
}
