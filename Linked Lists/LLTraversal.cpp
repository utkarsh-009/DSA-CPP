#include <iostream>
using namespace std;

// Creating Node Structure
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

// With pointer of head, we can traverse entire Linked List
void printLL(Node *head) // Giving head as parameter
{
    Node *curr = head;   // Creating a temp pointer for traversal
    while (curr != NULL) // NOTE: In condition, curr.next != null will not print last last node
    {
        cout << curr->data << " "; // Printing the data of curr node
        curr = curr->next;         // For jumping to next node
    }
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    printLL(head);
}
