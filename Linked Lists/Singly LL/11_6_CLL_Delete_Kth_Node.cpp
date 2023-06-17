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

void printCLL(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

// O(1): Store value of head's next as nextVal. Now, make head->next as head->next->next and assign head's val = nextVal
Node *delHeadCLL(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    int nextVal = head->next->data;
    head->next = head->next->next;
    head->data = nextVal;

    return head;
}

Node *delKthNode(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    if (k == 1)
    {
        return delHeadCLL(head);
    }

    Node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->next;
    }

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    head = delKthNode(head, 3);
    printCLL(head);
    return 0;
}
