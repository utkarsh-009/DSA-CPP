/*
Input: 25->36->47->58->69->80, x = 19
Output: 19 25 36 47 58 69 80

Input: 50->100, x = 75
Output: 50 75 100

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

// O(pos) => pos at which node is being inserted
Node *sortedInsert(Node *head, int k)
{
    // getting the prev node location of position, after which data is to be inserted
    Node *prev = NULL;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (curr->data >= k)
        {
            break;
        }
        prev = curr;
    }

    Node *newNode = new Node(k);
    // If the prev = NULL => Insert at begining
    if (prev == NULL)
    {
        newNode->next = head;
        return newNode;
    }

    //
    Node *temp = prev->next;
    prev->next = newNode;
    newNode->next = temp;

    return head;
}

int main()
{
    /* Start with the empty list */
    Node *head = NULL;
    head = sortedInsert(head, 5);
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 7);
    head = sortedInsert(head, 3);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, 9);

    cout << "Created Linked List\n";
    printList(head);

    return 0;
}
