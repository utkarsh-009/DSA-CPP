/*
  10
 / \
5  20
   / \
  30  6

O/P: 5
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

// M1: Recursive [TC: O(n), AS: O(h)]
int getSizeRecur(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return getSizeRecur(root->left) + getSizeRecur(root->right) + 1;
}

// M2: Irerative Using Level Order Traversal [TC: O(n), AS: O(w)]
int getSizeIter(Node *root)
{
    int size = 0;
    if (root == NULL)
    {
        return size;
    }

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();

        size++;

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }

    return size;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << getSizeIter(root);
}
