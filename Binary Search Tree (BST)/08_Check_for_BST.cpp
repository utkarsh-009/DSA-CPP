/*
Check if the tree is binary search tree.

M1: We pass a range for every node, initally from root (-INF to +INF). Then we update the ranges
as we traverse through the node. If node's value does not belong between the range => NOT BST
M2: We use a fact for this approach that inorder traversal of BST is always in increasing order. if
it is not in increasing order => NOT BST
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

// M1: [TC: O(n), AS: O(h)]
bool isBSTM1(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    return (root->key > min && root->key < max && isBSTM1(root->left, min, root->key) && isBSTM1(root->right, root->key, max));
}

// M2: [TC: O(n), AS: O(h)]
int previous = INT_MIN;
bool isBSTM2(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (isBSTM2(root->left) == false)
    {
        return false;
    }

    if (root->key <= previous)
    {
        return false;
    }

    previous = root->key;
    return isBSTM2(root->right);
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    ((isBSTM1(root, INT_MIN, INT_MAX)) ? cout << "Is BST" << endl : cout << "Not a BST" << endl);

    ((isBSTM2(root)) ? cout << "Is BST" << endl : cout << "Not a BST" << endl);

    return 0;
}