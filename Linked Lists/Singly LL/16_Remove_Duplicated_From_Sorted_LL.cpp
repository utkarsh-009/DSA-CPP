/*

Input: 2->2->4->5
Output: 2 4 5

Input: 2->2->2->2->2
Output: 2
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

// O(n): Removing the links with duplicate node and the deleting it.
Node *removeDuplicates(Node *head)
{
    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(4);

    printLL(head);
    cout << endl;
    removeDuplicates(head);
    printLL(head);
    cout << endl;
}