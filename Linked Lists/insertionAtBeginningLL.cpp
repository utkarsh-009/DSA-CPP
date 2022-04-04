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

    Node *temp; // Creating a temporary node
    // Declaring the value and its next pointer as head
    temp->data = x;
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
}
