#include <bits/stdc++.h>
using namespace std;

// Creating structure for Node
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// To print Linked List
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Using Hashing: [TC: O(n), AS: O(n)]
Node *cloneLLM1(Node *head)
{
    unordered_map<Node *, Node *> mp;

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        mp[curr] = new Node(curr->data);
    }

    for (auto x : mp)
    {
        Node *curr = x.first;
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
    }

    return mp[head];
}

// [TC: O(n), Auxillary Space: O(1)]
Node *cloneLLM2(Node *head)
{
    if (head == NULL)
        return NULL;

    // S1: inserting the clone nodes alternatively
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextNode = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = nextNode;

        curr = nextNode;
    }

    // S2: updating the current of clone nodes as clone node's random will be equal to curr's random's next.
    // NOTE: curr will be as curr = curr->next->next
    for (curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
    }

    Node *clone_head = head->next;
    // S3: Now separting clone nodes from original by updating the links
    Node *curr_clone = clone_head;
    curr = head;
    while (curr != NULL && curr_clone != NULL)
    {
        curr->next = curr->next->next;
        curr_clone->next = (curr_clone->next != NULL) ? curr_clone->next->next : NULL;

        // Updating curr and curr_clone
        curr = curr->next;
        curr_clone = curr_clone->next;
    }

    return clone_head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << "Original list : \n";
    printlist(head);

    cout << "\nCloned list : \n";
    Node *cloned_list = cloneLLM2(head);
    printlist(cloned_list);
}