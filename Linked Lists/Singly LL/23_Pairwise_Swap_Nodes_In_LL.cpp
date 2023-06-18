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
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Naive Swap by Value: [TC: O(n), AS: O(1)]
// The method is naive because if we the data to be swap large objects, they the swap by value cannot be used. Which causes overhead and becomes inefficient
void pairwiseSwapByVal(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
}

// Swap by pointer [TC: O(n), AS: O(1)]
Node *pairwiseSwapByPointer(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = head;
    Node *curr = head->next;

    // Swapping first two nodes
    Node *temp = curr->next;
    curr->next = prev;
    prev->next = temp;

    // Updating new head
    head = curr;

    // Updating curr node and next node
    curr = temp;
    Node *next = temp->next;

    // maintaining prev linked list link while swapping pointer of curr and next
    while (next != NULL)
    {
        // swapping by pointer
        temp = next->next;
        next->next = curr;
        curr->next = temp;

        // linking the prev linked list
        prev->next = next;

        // updating prev, curr and next pointer
        prev = curr;
        curr = temp;
        if (temp != NULL)
        {
            next = temp->next;
        }
        else
        {
            next = NULL;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    head = pairwiseSwapByPointer(head);
    cout << endl;
    printlist(head);
    return 0;
}
