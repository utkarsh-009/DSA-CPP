/*
Zig-Zog or Spiral Traversal
I/P:
  10
 / \
5  20
   / \
  30  6

O/P: 10 20 5 30 6
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

// [TC: O(n), AS: O(n)]
void spiralTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    bool reverse = false;
    while (!q.empty())
    {
        int qsize = q.size();
        stack<int> st;

        for (int i = 0; i < qsize; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (reverse)
                st.push(curr->data);
            else
                cout << curr->data << " ";

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }

        if (reverse)
        {
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }

            reverse = false;
        }
        else
        {
            reverse = true;
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

    spiralTraversal(root);
}
