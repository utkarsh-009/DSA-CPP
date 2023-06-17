/*
Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
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

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// O(n): Finding size of Linked List and then finding (sz-n+1)th element
int getNthFromEnd(Node *head, int n)
{
    int sz = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        sz++;
    }

    if (sz < n)
    {
        return -1;
    }

    int x = sz - n + 1;
    Node *curr = head;
    for (int i = 1; i < x; i++)
    {
        curr = curr->next;
    }

    return curr->data;
}

// Two Pointer: first and second pointer initialised to head, the second pointer is moved n positions ahead.
// Now, first pointer and second pointer both are moved until second becomes NULL. The first pointer points to nth node from end
int getNthFromEndEff(Node *head, int n)
{
    if (head == NULL)
        return -1;
    Node *first = head;
    for (int i = 0; i < n; i++)
    {
        // if first becomes NULL already before reaching nth position => return NULL
        if (first == NULL)
            return -1;
        first = first->next;
    }

    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }

    return second->data;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printList(head);
    cout << "\nNth node from end of Linked List: " << getNthFromEndEff(head, 2);
    return 0;
}
