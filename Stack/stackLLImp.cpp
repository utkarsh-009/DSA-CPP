#include <iostream>
using namespace std;

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