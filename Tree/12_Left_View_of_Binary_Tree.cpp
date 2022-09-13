/*
  10
 / \
5  20
   / \
  30  6

O/P: 10 5 30
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

// Recursive [TC: O(n), AS: O(h)]
/*
Intution:
We can keep track of the level of a node by passing a parameter to all recursive calls.
The idea is to keep track of the maximum level also. Whenever we see a node whose level is more than maximum level so far,
We print the node because this is the first node in its level (Because we are traversing left subtree before right subtree)

Algo:
Use of two variables:
    1.) level => current level
    2.) max_level => max level reached till now

if(max_level < level) =>
    Print First Node (As new level is reached)
    Update the max_level = level
Recursievly going to left subtree
Recursievly going to right subtree

*/
void printLeft(Node *root, int level, int *max_level)
{
    if (root == NULL)
    {
        return;
    }

    if (*max_level < level)
    {
        cout << root->key << " ";
        *max_level = level;
    }

    printLeft(root->left, level + 1, max_level);
    printLeft(root->right, level + 1, max_level);
}

void printLeftViewRecur(Node *root)
{
    int max_level = 0, level = 1;
    printLeft(root, level, &max_level); // maxlevel is passed by reference
}

// Iterative  [TC: O(n), AS: O(w)]
/*
 Intution: Using Level Order Traversal, print first node of every level.
 */
void printLeftViewIter(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int qSize = q.size();
        bool firstNode = true; // Use of bool firstNode to only print first node of the level

        for (int i = 0; i < qSize; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (firstNode) // Printing First Node
            {
                cout << curr->key << " ";
                firstNode = false; // After Printing First, we set bool firstNode as false
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    printLeftViewRecur(root);
}
