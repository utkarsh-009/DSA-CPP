
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
    if (first == NULL || first->next == second)
    {
        return first;
    }

    Node *curr = NULL, *head = NULL;
    Node *curr1 = first;
    Node *curr2 = second;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            Node *temp = new Node(curr1->data);
            if (curr == NULL)
            {
                head = temp;
                curr = head;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }
            curr1 = curr1->next;
        }
        else
        {
            Node *temp = new Node(curr2->data);
            if (curr == NULL)
            {
                head = temp;
                curr = head;
            }
            else
            {
                curr->next = temp;
                curr = curr->next;
            }
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL)
    {
        Node *temp = new Node(curr1->data);
        if (curr == NULL)
        {
            head = temp;
            curr = head;
        }
        else
        {
            curr->next = temp;
            curr = curr->next;
        }
        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        Node *temp = new Node(curr2->data);
        if (curr == NULL)
        {
            head = temp;
            curr = head;
        }
        else
        {
            curr->next = temp;
            curr = curr->next;
        }
        curr2 = curr2->next;
    }

    return head;
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
