/*
ind:  1   2   3
I/P: 10->20->30->40->NULL, x = 20

O/P: 2
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

int searchInLL(Node *head, int x)
{
    Node *curr = head;
    int pos = 1;

    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return pos;
        }

        curr = curr->next;
        pos++;
    }

    return -1;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    printLL(head);

    cout << endl;

    cout << "Position of element in LL: " << searchInLL(head, 20) << endl;
}