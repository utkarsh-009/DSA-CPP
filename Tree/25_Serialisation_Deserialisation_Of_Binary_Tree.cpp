/*
Serialise =>
      10
     / \
    5  20
   / \
  30  6

O/P: 10 5 30 6 20

Deserialise =>
10 5 30 6 20
O/P:
      10
     / \
    5  20
   / \
  30  6
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

const int EMPTY = -1;
void serialize(Node *root, vector<int> &serial)
{
    if (root == NULL)
    {
        serial.push_back(EMPTY);
        return;
    }

    serial.push_back(root->key);
    serialize(root->left, serial);
    serialize(root->right, serial);
}

int idx = 0;
Node *deserialize(vector<int> &serial)
{
    if (idx >= serial.size())
        return NULL;

    int val = serial[idx++];
    // Empty Node
    if (val == EMPTY)
        return NULL;

    Node *root = new Node(val);
    root->left = deserialize(serial);
    root->right = deserialize(serial);

    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
    else
    {
        cout << -1 << " ";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(30);
    root->left->right = new Node(6);
    root->right = new Node(20);

    vector<int> serial;
    serialize(root, serial);

    for (int x : serial)
    {
        cout << x << " ";
    }

    cout << endl;

    Node *newRoot = deserialize(serial);
    preorder(newRoot);
}