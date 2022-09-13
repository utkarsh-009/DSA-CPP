/*

  10
 / \
5  20
   / \
  30  6

O/P:
    10
    5 20
    30 6
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

//  [TC: O(n), AS:O(n)]
void printLevelOrderTravLineByLine(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false) // if queue is empty => Level Order Traversal Completed
    {
        int qSize = q.size();

        // Printing all nodes of each level
        for (int i = 0; i < qSize; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";

            // Put first left then right children in queue, if not null
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }

        // New Line
        cout << "\n";
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    printLevelOrderTravLineByLine(root);
}
