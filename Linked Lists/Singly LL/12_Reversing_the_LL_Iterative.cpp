/*

I/P: 10->20->30->NULL
O/P: 30->20->10->NULL

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

Node *revLL(Node *head)
{
    Node *curr = head;
    Node *prevTOcurr = NULL;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prevTOcurr;
        prevTOcurr = curr;
        curr = temp;
    }

    return prevTOcurr;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    printLL(head);

    cout << endl;

    printLL(revLL(head));
}
