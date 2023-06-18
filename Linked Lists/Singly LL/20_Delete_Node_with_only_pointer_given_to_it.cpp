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

// NOTE: Node to deleted will never be last node
// Intution O(1): We update the current data to current's next. The temp variable is store as the curr's next to delete it last.
// Current's next link is changed to Current's next's next link.
void deleteNode(Node *ptr)
{
    if (ptr->next == NULL)
        return;

    Node *temp = ptr->next;
    ptr->data = ptr->next->data;
    ptr->next = ptr->next->next;
    delete temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    Node *ptr = new Node(30);
    head->next->next = ptr;
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(25);
    printLL(head);
    cout << endl;
    deleteNode(ptr);
    printLL(head);
    return 0;
}
