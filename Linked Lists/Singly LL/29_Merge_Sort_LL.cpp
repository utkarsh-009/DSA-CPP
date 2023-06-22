
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

// Merge Function for Merging Sorted Linked List
Node *mergeLL(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *dummyHead = new Node(-1);
    Node *curr = dummyHead;

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            curr->next = first;
            first = first->next;
            curr = curr->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
            curr = curr->next;
        }
    }

    if (first != NULL)
    {
        curr->next = first;
    }
    else
    {
        curr->next = second;
    }

    return dummyHead->next;
}

// Function to split LL
Node *splitLL(Node *head)
{
    Node *slow = head, *fast = head;

    while (!fast && !fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // spliting LL into two parts
    Node *mid = slow->next;
    slow->next = NULL;

    return mid;
}

// Function to sort the given linked list using Merge Sort.
Node *mergeSortLL(Node *first)
{
    if (first == NULL || first->next == NULL)
    {
        return first;
    }

    Node *second = splitLL(first);

    first = mergeSortLL(first);
    second = mergeSortLL(second);

    return mergeLL(first, second);
}

int main()
{
    Node *head = new Node(30);
    head->next = new Node(20);
    head->next->next = new Node(40);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(50);

    printList(head);
    cout << endl;

    head = mergeSortLL(head);

    printList(head);
    cout << endl;
}
