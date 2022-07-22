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

struct Queue
{
    int size;
    Node *front, *rear;

    Queue(int c)
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);

        size++;
        if (front == NULL)
        {
            front = temp;
            rear = temp;

            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front->next == NULL)
        {
            rear = NULL;
        }

        delete (temp);
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }
};

void printQ(Queue *myQ)
{
    for (Node *curr = myQ->front; curr != NULL; curr = curr->next)
    {
        cout << curr->data << " ";
    }
}

int main()
{
    Queue *myQ = new Queue(5);
    cout << "Is Empty: " << myQ->isEmpty() << endl;

    Node *head;
    myQ->enqueue(1);
    myQ->enqueue(2);
    myQ->enqueue(3);
    myQ->enqueue(4);
    myQ->enqueue(5);

    printQ(myQ);
    cout << endl;
    cout << "Is Empty: " << myQ->isEmpty() << endl;

    myQ->dequeue();
    myQ->dequeue();

    printQ(myQ);
    cout << endl;

    cout << "Front is: " << myQ->getFront() << endl;
    cout << "Rear is: " << myQ->getRear() << endl;
}
