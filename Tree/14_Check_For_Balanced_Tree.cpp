/*
In a Balanced Binary Tree for every node, the difference between heights of left subtree and right subtree should not be more than one.
  10
 / \
5  20
   / \
  30  6

O/P: YES

  10
   \
   20
    \
     6

O/P: NO
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

// M1: Naive [TC: O(n*n), O(h)]
/*
Intution:
Finding height at every node and then checking if difference of left height and right height is less than or equal to 1.
Also, Recursively calling isBalanced for left subtree and right subtree
*/
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalancedM1(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int hLeft = height(root->left), hRight = height(root->right);

    return (abs(hLeft - hRight) <= 1 && isBalancedM1(root->left) && isBalancedM1(root->right)); // Recursively calling isBalanced for left subtree and right subtree
}

// M2:  [TC: O(n), AS: O(h)]
/*
Intution: Drill down recursion and as we go up again.
We check two things everytime:
    1.) Node's Height
    2.) Node's Left and Right Subtree Balanced or Not

NOTE: Initially, while moving from down we are defining null node's height as -1 (As they are below tree)

*/
bool isBalancedM2(Node *root)
{
    if (root == NULL) // Base Case
    {
        return 0;
    }

    int leftHeight = isBalancedM2(root->left); // Finding Left Node's Height
    if (leftHeight == -1)                      // If Tree Balanced => Returns Height of Left Node, else returns -1
    {
        return -1;
    }

    int rightHeight = isBalancedM2(root->right); // Finding Right Node's Height
    if (rightHeight == -1)                       // If Tree Balanced => Returns Height of Right Node, else returns -1
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) // Condition when Tree is Unbalanced
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1; // For Returning Height of Tree
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    cout << isBalancedM2(root);
}
