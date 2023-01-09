/*
Preorder Traversal: ROOT LEFT RIGHT

  10
 / \
5  20
   / \
  30  6

Preorder Traversal: 10 5 20 30 6

TC: O(n), AS: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

// Recursive
void preorderRecur(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorderRecur(root->left);
        preorderRecur(root->right);
    }
}

// Iterative
void preOrderIter(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;
    st.push(root);

    while (st.empty() == false)
    {
        Node *curr = st.top();
        st.pop();

        cout << curr->key << " ";

        // NOTE: stack works using LIFO (Last In First Out) principle.
        // Hence, we have to first push right node into stack before left node so as to get left node at top.
        if (curr->right != NULL)
        {
            st.push(curr->right);
        }

        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    preorderRecur(root);
    cout << endl;
    preOrderIter(root);
}