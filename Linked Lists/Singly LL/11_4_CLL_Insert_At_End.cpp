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

// O(n)
Node *insertAtEndCLL(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }

    Node *curr = head;
    do
    {
        curr = curr->next;
    } while (curr->next != head);

    curr->next = temp;
    temp->next = head;

    return head;
}

// O(1): insert new node at head's next and changing head to head->next
Node *insertAtEndCLLEff(Node *head, int x)
{
    Node *temp = new Node(x);

    Node *next = head->next;
    head->next = temp;
    temp->next = next;
    swap(head->data, temp->data);
    head = head->next;

    return head;
}

int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = insertAtEndCLLEff(head, 15);
    printCLL(head);
    return 0;
}
