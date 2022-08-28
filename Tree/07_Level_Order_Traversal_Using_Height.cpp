/*

  10
 / \
5  20
   / \
  30  6

O/P: 10 5 20 30 6

TC: O(n + n*h), AS: O(n*h)
*/

#include <iostream>
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

void printNodesAtLevelK(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->key << " ";
        return;
    }

    printNodesAtLevelK(root->left, k - 1);
    printNodesAtLevelK(root->right, k - 1);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    int h = height(root);

    for (int i = 1; i <= h; i++)
    {
        printNodesAtLevelK(root, i - 1);
    }
}