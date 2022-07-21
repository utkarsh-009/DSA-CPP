#include <iostream>
using namespace std;

struct Node
{
    int data; // Data to store in node

    // self-referential structure: Node
    Node *next; // next is a pointer that stores refernce of next node

    // Constructor to initialize data and next
    Node(int x)
    {
        int data = x;
        next = NULL; // Initialise next pointer as NULL
    }
};

int main()
{

    // 10-> 20-> 30
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
}