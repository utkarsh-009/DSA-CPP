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
    // Edge case
    if (head == NULL)
    {
        return -1;
    }

    // Base Condition
    if (head->data == x)
    {
        return 1;
    }

    // If not found during current recursive call
    else
    {
        int pos = searchInLL(head->next, x);
        if (pos == -1) // Return -1 to prev recursive call
        {
            return -1;
        }
        else // Return pos+1 to prev recursive call
        {
            return (pos + 1);
        }
    }
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
