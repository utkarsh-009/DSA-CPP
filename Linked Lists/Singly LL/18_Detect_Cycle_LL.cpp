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

// Using Map [TC: O(n), AS: O(n)]
bool detectLoopM1(Node *head)
{
    // your code here
    unordered_map<Node *, bool> mp;
    Node *curr = head;

    while (curr != NULL)
    {
        if (mp.find(curr) != mp.end())
        {
            return true;
        }
        mp[curr] = true;
        curr = curr->next;
    }

    return false;
}

// Modification of Linked list [TC: O(n), AS: O(1)]
bool detectLoopM2(Node *head)
{
    Node *curr = head;
    // Pointing all nodes to dummy nodes after visiting.
    Node *dummy = new Node(-1);
    while (curr != NULL)
    {
        // if curr->next = NULL => No loop
        if (curr->next == NULL)
        {
            return false;
        }
        // if curr->next->next points to the dummy node => the node is already visited. Hence, loop detected
        else if (curr->next->next == dummy)
        {
            return true;
        }

        Node *temp = curr;
        curr = curr->next;
        temp->next = dummy;
    }

    return false;
}

// Floyd Cycle Detection [TC: O(n), AS: O(1)]: Using Slow and Fast pointer
bool detectLoopM3(Node *head)
{
    // Base Case
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    // fast pointer moved at twice the speed of slow pointer.
    // At some instance, they will meet if loop exists else fast will reach null
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != NULL && fast->next != NULL && slow != fast);

    return slow == fast;
}

int main()
{
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;
    if (detectLoopM2(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}
