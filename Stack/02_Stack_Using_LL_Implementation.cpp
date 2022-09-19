#include <iostream>
using namespace std;

/*
Intution:
Considering head as top.
All Operations => O(1)
    push(x): sz++;
        Creating a new node temp (Node *temp = new Node(x))
        linking new node to head (temp->next = head)
        and updating new node as head i.e. top (head = temp)
    pop(): sz--;
        Storing head's data in poppedTop (poppedTop = head->data)
        Storing head node in temp for handling garbage collection (Node *temp = head;)
        Popping top from stack by updating head as head->next (head = head->next)
    peek(): return head->data, Edge Case: Top Does Not Exist, when head = NULL
    isEmpty(): return (head == NULL);
    size(): return sz;
*/
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

// Consider head as Top
struct MyStack
{
    Node *head; // head node considered as top
    int sz;     // size of stack (linked list)

    MyStack() // Constructor to initialise head as NULL , sz as 0
    {
        head = NULL;
        sz = 0;
    }

    // push function
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    // pop function
    int pop()
    {
        int poppedTop = head->data;

        Node *temp = head;
        head = head->next;

        delete (temp);
        sz--;

        return poppedTop;
    }

    // size function
    int size()
    {
        return sz;
    }

    // isEmpty function
    bool isEmpty()
    {
        return (head == NULL);
    }

    // peek function
    int peek()
    {
        if (head == NULL)
        {
            cout << "NO TOP" << endl;
            return -1;
        }
        return head->data;
    }

    // printing stack without affecting stack
    void printStack()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main()
{

    MyStack *s = new MyStack();
    // push
    s->push(10);
    s->push(20);
    s->push(30);

    // printing stack without affecting stack
    s->printStack();

    s->push(40);
    s->push(50);

    // To check if stack is empty or not
    cout << "Stack is Empty: " << s->isEmpty() << endl;

    // To get top of the stack
    cout << "Top of Stack is: " << s->peek() << endl;

    cout << "My Stack : " << endl;
    while (s->sz != 0)
    {
        cout << "|" << s->pop() << "|" << endl;
    }

    cout << endl;
    cout << "Stack is Empty: " << s->isEmpty() << endl;
}