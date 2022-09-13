/*
Printing Nodes at level-k of Tree (level starting from 0th i.e. root)
I/P: k = 2

  10
 / \
5  20
   / \
  30  6

O/P: 30 6

TC: O(n), AS: O(h)
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
/*
Intution:
Moving to left and right subtree recursiely along with decrementing value of k by 1 in every recursive call.
When k == 0 => kth level is reached
*/
// [TC: O(n), AS: O(h)]
void printNodesAtLevelK(Node *root, int k)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    if (k == 0) // When k == 0, kth level reached
    {
        cout << root->key << " ";
        return;
    }

    printNodesAtLevelK(root->left, k - 1);  // Moving to left subtree and decrementing k by 1
    printNodesAtLevelK(root->right, k - 1); // Moving to right subtree and decrementing k by 1
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    cout << "Nodes present at 2nd level of given Tree is: ";
    printNodesAtLevelK(root, 2);
}