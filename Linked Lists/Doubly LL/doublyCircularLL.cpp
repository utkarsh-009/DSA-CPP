#include <iostream>
using namespace std;

// Creating structure for Node
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};