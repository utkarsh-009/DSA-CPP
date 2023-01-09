/*
Postorder Traversal: LEFT RIGHT ROOT

  10
 / \
5  20
   / \
  30  6

Postorder Traversal: 5 30 6 20 10

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

void postorderRecur(Node *root)
{
    if (root != NULL)
    {
        postorderRecur(root->left);
        postorderRecur(root->right);
        cout << root->key << " ";
    }
}

void postorderIter(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || st.empty() == false)
    {
        // Reaching to left most node in the tree
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            // Now reaching to the right most node of the tree
            Node *temp = st.top()->right;

            // if right node is NULL
            if (temp == NULL)
            {
                // we assign stack's top (root node) which we want to print to temp and then pop it
                temp = st.top();
                st.pop();
                cout << temp->key << " ";

                // simillarly we run a while loop to print all the nodes whose temp = stack's top right
                while (st.empty() == false && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();

                    cout << temp->key << " ";
                }
            }
            else
            {
                // assign curr to right node, so as to traverse through its left subtree
                curr = temp;
            }
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

    postorderRecur(root);
    cout << endl;
    postorderIter(root);
}