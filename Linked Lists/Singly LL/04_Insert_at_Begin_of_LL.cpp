/*

I/P: 10->20->30->NULL, x = 5
O/P: 5->10->20->30->NULL

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

// Inserting Node at beginning of linked list
Node *insertAtBegin(Node *head, int x)
{

    Node *temp = new Node(x); // Creating a temporary node with initialising its value
    // Declaring its next pointer as head
    temp->next = head;

    // Returning the temp node
    return temp; // Temp will be our new head
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

    Node *head = NULL;
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);

    printLL(head);
}
