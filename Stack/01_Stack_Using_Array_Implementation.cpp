#include <iostream>
using namespace std;

/*
Intution:
Assigning capacity and Intialising top of stack as -1;
    push(x): Increment the top and insert arr[top] = x, Edge Case: Overflow, when top == cap - 1
    pop(): temp = arr[top], decrement the top and return temp, Edge Case: Underflow, when top = -1
    peek(): return arr[top], Edge Case: Top Does Not Exist, when top = -1
    isEmpty(): return (top == -1);
    size(): return top+1;
*/
struct MyStack
{
    int *arr; // Array to store stack
    int cap;  // Capacity of stack(array)
    int top;  // Top of the stack

    MyStack(int c) // Initialising capacity of stack, size of array and top using constructor
    {
        cap = c;
        arr = new int[cap];
        top = -1; // Top initialised as -1
    }

    // push function
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    // pop function
    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        int poppedTop = arr[top];
        top--;

        return poppedTop;
    }

    // peek function
    int peek()
    {
        if (top == -1)
        {
            cout << "No Top" << endl;
            return -1;
        }

        return arr[top];
    }

    // size function
    int size()
    {
        return top + 1;
    }

    // isEmpty function
    bool isEmpty()
    {
        return (top == -1);
    }
    // printing stack without affecting stack
    void printStack()
    {
        int ind = top;
        while (ind >= 0)
        {
            cout << "|" << arr[ind] << "|" << endl;
            ind--;
        }
    }
};

int main()
{

    MyStack *s = new MyStack(5);
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
    while (s->top != -1)
    {
        cout << "|" << s->pop() << "|" << endl;
    }

    cout << endl;
    cout << "Stack is Empty: " << s->isEmpty() << endl;
}