/*

I/P: 10->20->30->NULL
O/P: 30->20->10->NULL

*/

#include <iostream>
using namespace std;

// Creating structure for Node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// To print Linked List
void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// O(n): Keeping track of prev and curr in every recursive call.
Node *revLLRecur(Node *prev, Node *curr)
{
    if (curr == NULL)
        return prev;

    // Changing the links
    Node *nextNode = curr->next;
    curr->next = prev;

    // Recursively calling reverse function for next nodes
    return revLLRecur(curr, nextNode);
}

Node *revLL(Node *head)
{
    return revLLRecur(NULL, head);
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printLL(head);

    cout << endl;

    printLL(revLL(head));
}
