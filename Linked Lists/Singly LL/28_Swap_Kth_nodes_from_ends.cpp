/*
Input: N = 4,  K = 1, value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after swapping the 1st node from the beginning and end thenew list will be 4 2 3 1.

Input: N = 5,  K = 7, value[] = {1,2,3,4,5}
Output: 1
Explanation: K > N. Swapping is invalid. Return the head node as it is.
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

Node *swapkthnode(Node *head, int N, int K)
{
    if (K > N)
    {
        return head;
    }
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head, *fast = head;
    int pos1 = min(K - 1, N - K);
    int pos2 = max(K - 1, N - K);

    Node *prev_n1 = NULL, *n1 = NULL;
    Node *prev_n2 = NULL, *n2 = NULL;

    for (int i = 0; i < pos1; i++)
    {
        prev_n1 = slow;
        slow = slow->next;
    }
    n1 = slow;

    for (int i = 0; i < pos2; i++)
    {
        prev_n2 = fast;
        fast = fast->next;
    }
    n2 = fast;

    // cout<<slow->data<<" "<<fast->data<<endl;

    // C1: edge case: both pointers same
    if (slow == fast)
    {
        return head;
    }
    // C2: edge case: both pointers next to each other and are the only nodes in the LL
    else if (slow == head && slow->next == fast)
    {
        fast->next = slow;
        slow->next = NULL;

        return fast;
    }
    // C3: general edge case: pointers correspond to first and last node
    else if (slow == head)
    {
        Node *temp = slow->next;
        fast->next = temp;
        prev_n2->next = slow;
        slow->next = NULL;

        return fast;
    }
    // C4: general edge case: when both pointers next to each other
    else if (slow->next == fast)
    {
        Node *temp2 = fast->next;
        slow->next = temp2;
        prev_n1->next = fast;
        fast->next = slow;
    }
    // C5: General Case
    else if (slow != fast && slow->next != fast)
    {
        Node *temp1 = slow->next;
        Node *temp2 = fast->next;
        fast->next = temp1;
        slow->next = temp2;
        prev_n1->next = fast;
        prev_n2->next = slow;
    }

    // for(Node* curr = head; curr != NULL; curr=curr->next) {cout<<curr->data<<" ";}

    return head;
}