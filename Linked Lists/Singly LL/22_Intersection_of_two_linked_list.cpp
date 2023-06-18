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

// Using Unordered_map to store references of list1 and using find function for every node of list2.
int getIntersectionM1(Node *head1, Node *head2)
{
    unordered_set<Node *> s;
    Node *curr = head1;
    while (curr != NULL)
    {
        s.insert(curr);
        curr = curr->next;
    }
    curr = head2;
    while (curr != NULL)
    {
        if (s.find(curr) != s.end())
            return curr->data;
        curr = curr->next;
    }
    return -1;
}

// O(1) Space:
// Intution: if len of l1 > len of l2, then len(l1) - len(l2) => the extra node in l1. Hence, we will traverse those extra nodes.
// Now we will traverson l1 and l2 simultaneously until they both become equal.

int findLen(Node *head)
{
    int len = 0;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        len++;

    return len;
}

// head1's Linked List Len is greater by len x
int intersectionNode(Node *head1, Node *head2, int x)
{
    Node *curr1 = head1, *curr2 = head2;
    for (int i = 0; i < x && curr1 != NULL; i++)
    {
        curr1 = curr1->next;
    }

    while (curr1 != NULL && curr2 != NULL && curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    if (curr1 == NULL)
        return -1;

    return curr1->data;
}

int getIntersectionM2(Node *head1, Node *head2)
{
    int len1 = findLen(head1);
    int len2 = findLen(head2);

    int x = abs(len1 - len2);
    if (len1 > len2)
    {
        return intersectionNode(head1, head2, x);
    }
    else
    {
        return intersectionNode(head2, head1, x);
    }
}

int main()
{
    /*
    Creation of two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
*/

    Node *newNode;

    Node *head1 = new Node(10);

    Node *head2 = new Node(3);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout << getIntersectionM2(head1, head2);
}