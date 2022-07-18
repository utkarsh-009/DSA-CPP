#include <iostream>
using namespace std;

// Node structure
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

void recur_LLprint(Node *head)
{
    if (head == NULL) // If head is equal to null, return void
    {
        return;
    }
    cout << head->data << " "; // Else return data
    recur_LLprint(head->next); // Performing Print Linked List function recursively on next node i.e. head.next
}

int main()
{

    Node *head = new Node(50);
    head->next = new Node(40);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(10);

    recur_LLprint(head);
}
