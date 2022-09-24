/*
  10
 / \
5  20
   / \
  30  6
O/P:
    10
   / \
  20  5
 / \
6 30
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

// Recursive [TC: O(n), AS: O(h)] // Aux Space is calculated considering Recursion Call Stack, AS would be O(1)
/* Intution: Calling Mirror fnc recursievly for left and right subtree and then swapping its left and right children
resulting in swap of left and right subtree.
*/
void mirrorRecur(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct Node *temp;

        mirrorRecur(root->left);  // mirroring left subtree recursievly
        mirrorRecur(root->right); // mirroring right subtree recursievly

        // Swapping pointers of left and right children
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// Iterative [TC: O(n), AS: O(w)]
// Intution : While doing level order traversal, swap left and right children of every node
void mirrorIter(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        swap(curr->left, curr->right); // swap left child with right child

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(15);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << "\n Inorder traversal of the constructed tree is \n";
    inOrder(root);

    /* Convert tree to its mirror */
    mirrorRecur(root);

    /* Print inorder traversal of the mirror tree */
    cout << "\n Inorder traversal of the mirror tree is \n";
    inOrder(root);
}
