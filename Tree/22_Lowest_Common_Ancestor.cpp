/*
LCA of 5 and 6
  10
 / \
5  20
   / \
  30  6

O/P: 10

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Good Method1: [TC: O(n), AS: O(n)]
/*
Find path of node1 from root to itself.
Find path of node2 from root to itself.

Now the last same node in both paths will be the LCA
*/
// Finds path from root to given node
bool findPath(Node *root, vector<Node *> &path, int node)
{
    if (root == NULL)
        return false;

    path.push_back(root);

    if (root->key == node)
        return true;

    if (findPath(root->left, path, node) || findPath(root->right, path, node))
        return true;

    path.pop_back();

    return false;
}

Node *lcaM1(Node *root, int n1, int n2)
{
    vector<Node *> p1, p2;

    // if any node does not exists in the tree
    if (findPath(root, p1, n1) == false || findPath(root, p2, n2) == false)
        return NULL;

    // the last common node in the path will be lca
    Node *lca = root;
    for (int i = 0; i < min(p1.size(), p2.size()); i++)
    {
        if (p1[i] == p2[i])
        {
            lca = p1[i];
        }
        else
        {
            break;
        }
    }

    return lca;
}

// Method2 Space Optimised: [TC: O(n), AS: O(h)]
/*
NOTE: Condition for this approach is that both the nodes should be present in the tree.
if not present, the incorrect results will be printed.
Cases during traversal for every node
1.) if it is same as n1 / n2
2.) if one of its subtree contains n1 and other contains n2
3.) if one of its subtree contains both n1 and n2
4.) if none of its subtree contain any of n1 and n2
*/
Node *lcaM2(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // C1:
    if (root->key == n1 || root->key == n2)
        return root;

    Node *lca1 = lcaM2(root->left, n1, n2);
    Node *lca2 = lcaM2(root->right, n1, n2);

    // lca found => return the lca
    if (lca1 != NULL && lca2 != NULL)
        return root;

    // lca1 is present at left side => we return lca1 to find lca in that subtree
    if (lca1 != NULL)
        return lca1;
    // lca2 is present at right side => we return lca2 to find lca in that subtree
    else
        return lca2;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    Node *lca = lcaM2(root, 30, 6);
    cout << lca->key << endl;
}
