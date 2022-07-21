#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
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

Node *revDLL(Node *head)
{
    Node *curr = head;
    Node *prevTOcurr = NULL;
    while (curr != NULL)
    {
        prevTOcurr = curr->prev;
        curr->prev = curr->next;
        curr->next = prevTOcurr;

        curr = curr->prev;
    }

    return prevTOcurr->prev;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;

    temp1->next = temp2;
    temp2->prev = temp1;

    printLL(revDLL(head));
}
