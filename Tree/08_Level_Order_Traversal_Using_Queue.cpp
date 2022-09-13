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
#include <queue>
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
For each node:
1.) The node is visited
2.) Then it’s child nodes are put in a FIFO queue.
Note: Initially push root in queue

Algorithm:
1) Create an empty queue q
2) push temp_node = root [start from root]
3) Loop while q not empty
    a) print temp_node->data.
    b) Dequeue node from q.
    c) Enqueue temp_node's children [first left then right children] to q
*/

// [TC: O(n), AS: O(n)]
void printLevelOrderTrav(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    // Every Node is Visited, then it’s child nodes are put in a FIFO queue.
    while (q.empty() == false) // if queue is empty => Level Order Traversal Completed
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
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(6);

    printLevelOrderTrav(root);
}
