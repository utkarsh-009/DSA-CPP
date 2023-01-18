/*
Given the root of a binary search tree and K as input, find Kth smallest element in BST.

NOTE:
M1 (TC: O(n), AS: O(h)) : Use any standard traversal technique and increment count, until (count == k) => cout<<root->val; return ;
M2 (TC: O(h), AS: O(h)): Using Augmented Tree Data Structure having lCount variable.
Intution: To find kth smallest element we will find an element having (k-1) node in its left subtree.
Approach:
    Compare (lCount + 1) with k
    ->if same => return root
    ->if greater => recur for left subtree with same k
    ->if smaller => recur for right subtree with k as (k - lcount - 1)
    NOTE: if k = 7, lcount = 4 => lcount + 1 = 5
        We recursively call for (k-(lcount+1)) => (k-lcount-1) i.e. finding (7-5) = 2nd smallest element in right subtree

*/

#include <bits/stdc++.h>
using namespace std;

// Augmented Tree Data Structure, introducing variable lCount (lCount => Count of nodes in left subtree)
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int lCount;
    Node(int k)
    {
        key = k;
        left = right = NULL;
        lCount = 0;
    }
};

void kthSmallestNaive(Node *root, int k, int &count)
{
    if (root != NULL)
    {
        kthSmallestNaive(root->left, k, count);
        count++;
        if (count == k)
        {
            cout << root->key;
            return;
        }
        kthSmallestNaive(root->right, k, count);
    }
}

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }

    if (root->key > x)
    {
        root->left = insert(root->left, x);

        // increasing lCount as node is inserted at left subtree
        root->lCount++;
    }

    else if (root->key < x)
    {
        root->right = insert(root->right, x);
    }

    return root;
}

Node *kthSmallest(Node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }

    int count = root->lCount + 1;
    if (count == k)
    {
        return root;
    }

    if (count > k)
    {
        return kthSmallest(root->left, k);
    }

    return kthSmallest(root->right, k - count);
}

int main()
{

    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root = insert(root, x);

    int k = 4;
    Node *res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->key;

    cout << endl;
    cout << "K-th Smallest Element is ";

    int count = 0;
    kthSmallestNaive(root, k, count);
    return 0;
}