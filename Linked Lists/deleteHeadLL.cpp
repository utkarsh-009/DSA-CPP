/*

I/P: 10->20->30->NULL
O/P: 20->30->NULL

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

Node *delHead(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head->next;
    delete (head);

    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }

    cout << endl;

    Node *newHead = delHead(head);
    for (Node *curr = newHead; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }
}