#include <iostream>
using namespace std;

struct Node
{
    int key;     // value stored in node
    Node *left;  // left child
    Node *right; // right child

    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
}