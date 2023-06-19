#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

// Naive Method: [TC: O(n), As: O(1)]
// Using Array: Store all the data of nodes in array, now check palindrome in the array
// USing Stack: Store all the data of nodes in stack, now iterate the LL again and pop the data when matched

// Reverse LL
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rest_head = reverseList(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}

// Check palindrome by modifying the array.
bool isPalindrome(Node *head)
{
    // Base Case
    if (head == NULL)
        return true;

    // Getting the middle of LL
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversing the slow's next and assigning the head as rev
    Node *rev = reverseList(slow->next);
    Node *curr = head;

    // Now check curr and rev are equal until rev becomes NULL.
    while (rev != NULL)
    {
        if (rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }
    return true;
}

int main()
{
    Node *head = new Node('g');
    head->next = new Node('f');
    head->next->next = new Node('g');
    if (isPalindrome(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
