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

void printCLL(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

Node *insertAtBeginCLL(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }

    Node *tail = head;
    do
    {
        tail = tail->next;
    } while (tail->next != head);

    Node *temp = new Node(x);
    tail->next = temp;
    temp->next = head;

    return temp;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = insertBegin(head, 15);
    printlist(head);
    return 0;
}
