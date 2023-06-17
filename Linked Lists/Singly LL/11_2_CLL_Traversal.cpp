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

// To print Circular Linked List
void printCLL(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    for (Node *curr = head->next; curr != head; curr = curr->next)
    {
        cout << curr->data << " ";
    }
}

// do while loop better implementation
/*

void printCLL(Node *head)
{
    if (head == NULL)
        return;

    Node* curr = head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != head)
}

*/

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;

    printCLL(head); // Infinite loop
}
