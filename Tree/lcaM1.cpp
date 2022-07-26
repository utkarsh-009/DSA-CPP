/*
LCA of 5 and 6
  10
 / \
5  20
   / \
  30  6

O/P: 10

TC: O(n), AS: O(n)
*/

#include <iostream>
#include <vector>
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

bool findPath(Node *root, vector<Node *> &p, int n) // Function to find path from root to given node with key n
{
    if (root == NULL) // Base condition
    {
        return false;
    }

    p.push_back(root); // We initially push the root inside path p vector

    if (root->key == n) // To check if root value is equal to n
    {
        return true;
    }

    if (findPath(root->left, p, n) || findPath(root->right, p, n)) // calling these two function recursievly to update the path vector
    {
        return true;
    }

    p.pop_back(); // If the path chosen is wrong, we will remove the recently added node
    return false;
}

Node *lca(Node *root, int n1, int n2)
{
    vector<Node *> path1, path2; // path1/path2 vector to store path from root to n1/n2 respectievly

    // if n1/n2 not present in tree
    if (findPath(root, path1, n1) == false || findPath(root, path2, n2) == false) // NOTE: this will also calculate path1 and path2
    {
        return NULL;
    }

    for (int i = 0; i < min(path1.size() - 1, path2.size() - 1); i++) // The node just before the first unequal node will be LOWEST COMMON ANCESTOR
    {
        if (path1[i + 1] != path1[i + 1])
        {
            return path1[i];
        }
    }

    return NULL;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);
}
