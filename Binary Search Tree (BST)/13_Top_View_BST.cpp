/*

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

// M1:Using Map and Level Order Traversal
void topView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false)
    {
        Node *node = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (mp.find(hd) == mp.end())
        {
            mp[hd] = node->key;
        }

        if (node->left != NULL)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto x : mp)
    {
        cout << x.second << " ";
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    topView(root);

    return 0;
}
