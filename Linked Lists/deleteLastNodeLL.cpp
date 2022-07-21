/*

I/P: 10->20->30->NULL
O/P: 10->20->NULL

*/
#include <iostream>
using namespace std;

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

Node *deleteLastNode(Node *head)
{
    Node *curr = head;
    if (head == NULL)
    {
        return NULL;
    }

    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    delete (curr->next);
    curr->next = NULL;

    return head;
}

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

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printLL(head);
    head = deleteLastNode(head);

    cout << endl;
    printLL(head);
}