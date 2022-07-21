/*
ind:  1   2   3
I/P: 10->20->30->NULL, pos = 2, data = 50

ind:  1   2   3   4
O/P: 10->50->20->30->NULL
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

Node *insertAtGivenPos(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    Node *curr = head;

    if (pos == 1 || head == NULL)
    {
        temp->next = head;
        return temp;
    }

    while (pos - 2 && curr->next != NULL)
    {
        curr = curr->next;
        pos--;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printLL(head);

    head = insertAtGivenPos(head, 2, 50);
    cout << endl;
    printLL(head);
}