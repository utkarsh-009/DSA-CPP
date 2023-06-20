/*
I/P: inorder =  {5, 10, 30, 20, 6}
     preorder = {10, 5, 20, 30, 6}

O/P:
  10
 / \
5  20
   / \
  30  6

inorder = {5,10,30,20,6}
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

//  [TC: O(n*n), AS: O(n)]
/*
Algorithm:
NOTE: First Element of Preorder Traversal is Root of the Tree.

1.) Pick element from preorder one-by-one using preIndex [preIndex = 0 to preIndex = n-1] & create node
2.) Store the value of preorder[preIndex] in curr variable and then Increment the preorder index (preIndex)
3.) Create Node of with value equal to curr
4.) Search the curr element in inorder traversal array and return its index in variable inIndex
5.) Call the build left subtree from inorder inorder_end to inIndex-1     [root->left = buildTree(preorder, inorder, inorder_start, inIndex - 1);]
6.) Call the build right subtree from inorder inIndex+1 to inorder_end    [root->right = buildTree(preorder, inorder, inIndex + 1, inorder_end);]
7.) Return the node

*/
int search(int inorder[], int inorder_start, int inorder_end, int curr) // To search the curr element in inorder traversal array and return its index in variable inIndex
{
    for (int i = inorder_start; i <= inorder_end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }

    return -1; // When curr not found, This case is not possible
}

Node *buildTree(int preorder[], int inorder[], int inorder_start, int inorder_end)
{
    static int preIndex = 0;

    if (inorder_start > inorder_end) // Edge Case
    {
        return NULL;
    }

    int curr = preorder[preIndex];
    preIndex++;
    Node *root = new Node(curr);

    if (inorder_start == inorder_end) // Base Case: Inorder Traversal has only one element
    {
        return root;
    }

    int inIndex = search(inorder, inorder_start, inorder_end, curr);
    root->left = buildTree(preorder, inorder, inorder_start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, inorder_end);

    return root;
}

void printInorder(Node *node)
{
    if (node != NULL)
    {
        printInorder(node->left);
        cout << node->key << " ";
        printInorder(node->right);
    }
}

// [TC: O(n), AS: O(n)]
// Using HashMaps to stores inorder values as key and their indexes are value.
Node *buildTreeEff(int preorder[], int inorder_start, int inorder_end, unordered_map<int, int> &mp)
{
    static int preIdx = 0;
    // Base Case
    if (inorder_start > inorder_end)
        return NULL;

    Node *root = new Node(preorder[preIdx++]);

    int inIdx = mp[root->key];
    root->left = buildTreeEff(preorder, inorder_start, inIdx - 1, mp);
    root->right = buildTreeEff(preorder, inIdx + 1, inorder_end, mp);

    return root;
}

int main()
{
    int in[] = {5, 10, 30, 20, 6};
    int pre[] = {10, 5, 20, 30, 6};

    unordered_map<int, int> mp;
    for (int i = 0; i < 5; i++)
    {
        mp[in[i]] = i;
    }

    Node *root1 = buildTree(pre, in, 0, 4);
    Node *root2 = buildTreeEff(pre, 0, 4, mp);
    printInorder(root1);
    cout << endl;
    printInorder(root2);
}
