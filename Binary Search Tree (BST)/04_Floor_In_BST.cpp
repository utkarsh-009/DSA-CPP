/*
We need to find Floor of given value in BST. Floor is the closest smaller or equal to value.
If no such value present we return -1.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

int BSTFloor(Node *root, int x)
{
    int floor = -1;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->key == x)
        {
            return x;
        }
        else if (curr->key > x)
        {
            curr = curr->left;
        }
        else
        {
            floor = curr->key;
            curr = curr->right;
        }
    }

    return floor;
}

int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int x = 17;

    cout << "Floor: " << BSTFloor(root, 17);
}
