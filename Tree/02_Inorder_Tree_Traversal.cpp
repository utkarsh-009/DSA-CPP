/*
Inorder Traversal: LEFT ROOT RIGHT

  10
 / \
5  20
   / \
  30  6

Inorder Traversal: 5 10 30 20 6

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

void inorderRecur(Node *root)
{
    if (root != NULL)
    {
        inorderRecur(root->left);
        cout << (root->key) << " ";
        inorderRecur(root->right);
    }
}

void inorderIter(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;
    Node *curr = root;

    // Run the loop until (curr is not null or stack is not empty)
    while (curr != NULL || st.empty() == false)
    {
        // Reaching to the left most Node of the curr Node
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        // Now as curr is NULL and at top of stack we have unvisited leftmost node
        curr = st.top(); // As curr is NULL, we will assign the unvisited leftmost node to it
        st.pop();

        cout << curr->key << " ";

        // As we have visited the node and its left subtree. Now, it's right subtree's turn
        curr = curr->right;
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    inorderRecur(root);
    cout << endl;
    inorderIter(root);
}