/*
Inorder conversion of Binary Tree to Doubly Linked List.
    10
    / \
   5  20
      / \
     30  35
O/P:  5<->10<->30<->20<->35 (Inorder Traversal)
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

/*
Intution: Using Inorder Traversal and maintaing prev pointer which will help us to connect current node with prev
NOTE:
1. For first node, prev is going to have NULL value => Which we will assign as head
2. For all other nodes, prev is going to have previously visited node as reference
*/

// Using Inorder Traversal [TC: O(n), AS: O(n)]
Node *BinTreeToDLL(Node *root) // root is the current node pointer
{
    if (root == NULL)
    {
        return root;
    }
    static Node *prev = NULL;
    Node *head = BinTreeToDLL(root->left); // INORDER TRAVERSAL: left subtree

    // For 1st Nodes (Head)
    if (prev == NULL) // first node, prev is going to have NULL value = > Which we will assign as head
    {
        head = root;
    }

    // For all other Nodes
    else // Linking prev and current pointers
    {
        root->left = prev;
        prev->right = root;
    }

    prev = root;               // Updating prev as current node
    BinTreeToDLL(root->right); // INORDER TRAVERSAL: right subtree

    return head;
}

void printDLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    Node *head = BinTreeToDLL(root);
    printDLL(head);
}
