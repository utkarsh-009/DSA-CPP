/*
  41
 / \
5  36
   / \
  30  6

O/P: 10 5 30
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

/*
Intution:
1. Firstly, intialise sum as 0
2. Then,
    Check if left subtree is null or not
    Check if right subtree is null or not
3. Checking CSP Recursievly in Left and right subtree
*/
// Recursive [TC: O(n), AS: O(h)]
bool isCSP(Node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL) // Edge Cases
    {
        return true;
    }

    int sum = 0;
    if (root->left != NULL) // Left node value added to sum
    {
        sum += root->left->key;
    }
    if (root->right != NULL) // Right node value added to sum
    {
        sum += root->right->key;
    }

    // Value of current root == current childeren sum && checking CSP in left and right subtree
    return (sum == root->key && isCSP(root->left) && isCSP(root->right));
}

//  [TC: ,AS: ]

int main()
{
    Node *root = new Node(41);
    root->left = new Node(5);
    root->right = new Node(36);
    root->right->left = new Node(30);
    root->right->right = new Node(6);
}
