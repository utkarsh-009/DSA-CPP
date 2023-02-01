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

// Inorder: [TC: O(n), AS: O(1)]
/*
Intution: While traversing in inorder, we always move left root right then to parent of the root.
We can use this observation and **create a link between rightmost node of root and parent of root.**
*/
vector<int> getInorder(Node *root)
{
    vector<int> inorder;
    Node *curr = root;
    while (curr != NULL)
    {
        // When left subtree is empty => push curr into vector and move curr to right subtree
        if (curr->left == NULL)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        // Creating link
        else
        {
            // prev node will help to create the link
            Node *prev = curr->left;

            // moving prev to rightmost node:
            while (prev != NULL && prev != curr)
            {
                prev = prev->right;
            }

            // linking rightmost node to current 
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}