/*
Given a binary search tree and sum, we need to find sum of nodes in all vertical lines
starting from leftmost line to rightmost.

Intution: Using map and maintaining horizontal distance, we maintain sum for each horizontal distance.
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

// M1: Using Map [TC: O(n), AS: O(n)]
void vSum(Node *root, map<int, int> &mp, int hd)
{
    if (root != NULL)
    {
        vSum(root->left, mp, hd - 1);
        mp[hd] += root->key;
        vSum(root->right, mp, hd + 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(50);
    root->left->left = new Node(30);
    root->left->right = new Node(40);

    map<int, int> mp;
    vSum(root, mp, 0);

    for (auto x : mp)
    {
        cout << x.second << " ";
    }
}
