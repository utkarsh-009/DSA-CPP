#include <bits/stdc++.h>
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

// Using slow and fast pointer
void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != NULL && fast->next != NULL && slow != fast);

    // cycle does not exist
    if (slow != fast)
        return;

    // finding the start point of cycle
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // as now both are in same position, we move fast until => fast's next becomes slow.
    while (fast->next != slow)
    {
        fast = fast->next;
    }

    // remove the link
    fast->next = NULL;
}

int main()
{
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;
    detectRemoveLoop(head);
    return 0;
}