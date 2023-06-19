/*
Input: N = 4, M = 3
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
*/
#include <bits/stdc++.h>
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

Node *mergeTwoSortedLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *prev = NULL;
    Node *head = NULL;
    Node *curr1 = head1;
    Node *curr2 = head2;

    // Setting head and prev
    if (curr1->data < curr2->data)
    {
        head = curr1;
        prev = curr1;
        curr1 = curr1->next;
    }
    else
    {
        head = curr2;
        prev = curr2;
        curr2 = curr2->next;
    }

    // Merging LL while maintaing the prev node of merged LL
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        else
        {
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
    }

    // Merging rest of the list1
    while (curr1 != NULL)
    {
        prev->next = curr1;
        prev = curr1;
        curr1 = curr1->next;
    }

    // Merging rest of the list2
    while (curr2 != NULL)
    {
        prev->next = curr2;
        prev = curr2;
        curr2 = curr2->next;
    }

    return head;
}

int main()
{
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    Node *b = new Node(5);
    b->next = new Node(35);
    printlist(mergeTwoSortedLL(a, b));
    return 0;
}
