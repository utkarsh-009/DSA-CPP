/*
Diameter of Binary Tree
I/P:
  10
 / \
5  20
   / \
  30  6

O/P: 4(5->10->20->30 or 5->10->20->6)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};

// Naive method: [TC: O(n*n), AS: O(n)]
int height(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// diameter of a node can be defined as 1+ left subtree height + right subtree height
int diameterNaive(Node *root)
{
    if (root == NULL)
        return 0;

    int d1 = 1 + height(root->left) + height(root->right);
    // recursievly find diameter for left subtree
    int d2 = diameterNaive(root->left);
    // recursievly find diameter for right subtree
    int d3 = diameterNaive(root->right);

    return max(d1, max(d2, d3));
}

// Better Method: [TC: O(n), AS: O(n)] => Precomputing heights of nodes in O(n)
int height(Node *root, unordered_map<Node *, int> &mp)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left, mp);
    mp[root->left] = lh;
    int rh = height(root->right, mp);
    mp[root->right] = rh;

    return 1 + max(lh, rh);
}

// O(n)
int findDiameterBetter(Node *root, unordered_map<Node *, int> &mp)
{
    if (root == NULL)
        return 0;

    int d1 = 1 + mp[root->left] + mp[root->right];
    // recursievly find diameter for left subtree
    int d2 = findDiameterBetter(root->left, mp);
    // recursievly find diameter for right subtree
    int d3 = findDiameterBetter(root->right, mp);

    return max(d1, max(d2, d3));
}

// Better [TC: O(n), AS: O(n)]
int diameterBetter(Node *root)
{
    unordered_map<Node *, int> mp;
    height(root, mp);

    return findDiameterBetter(root, mp);
}

// Efficient [TC: O(n), AS: O(h)]: No need of map
int diameter = 0;
int diameterUsingHeight(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = diameterUsingHeight(root->left);
    int rh = diameterUsingHeight(root->right);

    diameter = max(diameter, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    diameterUsingHeight(root);
    cout << diameter << endl;
}
