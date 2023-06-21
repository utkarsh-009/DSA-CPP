/*
IMP condition: Given node should be leaf node
Time required from node 30 (Leaf Node)
  10
 / \
5  20
   / \
  30  6

*/
O/P: 4

#include <bits/stdc++.h>
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

/*
Intution: The Time require to burn complete tree => The problem is equivalent to find distance of farthest node from given node.

burnTime function:
-> It computes two values for every node
1.) Distance from the given leaf node. Only if leaf node is descendant of the current node. Else it will store -1.
2.) Height of node considering it as root.

*/
int res = 0;
int burnTime(Node *root, int leaf, int &dist)
{
  if (root == NULL)
    return 0;

  if (root->key == leaf)
  {
    dist = 0;
    return -1;
  }

  int lDist = -1, rDist = -1;
  // computes left subtree height and right subtree height
  int lh = burnTime(root->left, leaf, lDist);
  int rh = burnTime(root->right, leaf, rDist);

  // lDist != -1 => leaf node is descendant of current node and it lies in left subtree of the current node
  if (lDist != -1)
  {
    // Note: farthest node calculation is simillar to finding diameter of that node

    // distance of leaf from current node
    dist = lDist + 1;

    // Diameter = Left Dist + Right Height => Furthest Node
    res = max(res, rh + dist);
  }
  // rDist != -1 => leaf node is descendant of current node and it lies in right subtree of the current node
  else if (rDist != -1)
  {
    // Note: farthest node calculation is simillar to finding diameter of that node

    // distance of leaf from current node
    dist = rDist + 1;

    // Diameter = Right Dist + Left Height => Furthest Node
    res = max(res, lh + dist);
  }

  // Return height of given node
  return 1 + max(lh, rh);
}

int main()
{

  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->left->left->left = new Node(60);
  root->left->left->left->left = new Node(70);
  int dist = -1;
  int leaf = 50;
  burnTime(root, leaf, dist);
  cout << res;
}