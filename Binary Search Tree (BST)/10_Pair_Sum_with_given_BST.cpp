/*
Given a binary search tree and sum, we have to whether there exist any two nodes who's sum
is equal to given sum.

M1: Using Inorder Traversal
M2: Using Hashing
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

// M1: Using Inorder Traversal  [TC: O(n), AS: O(n)]
void inorderBST(Node *root, vector<int> &inorder)
{
    if (root != NULL)
    {
        inorderBST(root->left, inorder);
        inorder.push_back(root->key);
        inorderBST(root->right, inorder);
    }
}

void findPairWithSumM1(Node *root, int sum)
{
    vector<int> inorder;
    inorderBST(root, inorder);

    int low = 0, high = inorder.size();
    while (low < high)
    {
        int s = inorder[low] + inorder[high];
        if (s == sum)
        {
            cout << inorder[low] << " " << inorder[high] << endl;
            return;
        }
        else if (s > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }

    cout << -1 << endl;
}

// M2: Using Hashing [TC: O(n), AS: O(n)]
void findPairWithSumM2(Node *root, unordered_set<int> &s, int sum)
{
    if (root != NULL)
    {
        findPairWithSumM2(root->left, s, sum);
        if (s.find(sum - root->key) != s.end())
        {
            cout << root->key << " " << sum - root->key;
        }
        else
        {
            s.insert(root->key);
        }

        findPairWithSumM2(root->right, s, sum);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(20);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);
    root->right->right->left = new Node(25);

    int sum = 33;
    unordered_set<int> s;

    findPairWithSumM1(root, sum);
    findPairWithSumM2(root, s, sum);

    return 0;
}