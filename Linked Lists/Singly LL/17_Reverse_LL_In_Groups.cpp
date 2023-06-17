/*

Input: 1->2->2->4->5->6->7->8, K = 4
Output: 4 2 2 1 8 7 6 5

Input: 1->2->3->4->5, K = 3
Output: 3 2 1 5 4
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

// Recursive Solution: TC: O(n), AS: O(n/k)
Node *reverseGroupOfSizeKRecur(Node *head, int K)
{
    int sz = 0;
    Node *prev = NULL;
    Node *curr = head;

    // Size of group should be less than or equal to k and curr should not be null.
    while (curr != NULL && sz < K)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        sz++;
    }

    // if curr != NULL => last group has not been reversed => we need to reverse the rest of the linked list
    if (curr != NULL)
    {
        Node *rest_head = reverseGroupOfSizeKRecur(curr, K);
        head->next = rest_head;
    }

    // return prev
    return prev;
}

// Iterative Solution: TC: O(n), AS: O(1)
Node *reverseGroupOfSizeKIter(Node *head, int K)
{
    Node *lastPrev = NULL;
    Node *curr = head;
    Node *newHead = NULL;
    bool firstPass = true;

    while (curr != NULL)
    {
        Node *firstNode = curr;
        Node *prev = NULL;
        int sz = 0;
        while (curr != NULL && sz < K)
        {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;

            sz++;
        }

        // Storing the new head of the LL.
        if (firstPass)
        {
            newHead = prev;
            firstPass = false;
        }
        // Linking the previous group to current group
        else
        {
            lastPrev->next = prev;
        }

        // After reversing first node becomes last node
        lastPrev = firstNode;
    }

    return newHead;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);
    printLL(head);
    head = reverseGroupOfSizeKIter(head, 3);
    cout << endl;
    printLL(head);
    return 0;
}
