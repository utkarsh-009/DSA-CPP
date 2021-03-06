#include <iostream>
using namespace std;

struct Queue
{
    int size, cap;
    int *arr;

    Queue(int c)
    {
        size = 0;
        cap = c;
        arr = new int[cap];
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            return;
        }

        arr[size] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            return;
        }

        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[0];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[size - 1];
    }
};

void printQ(Queue *myQ)
{
    for (int i = 0; i < myQ->size; i++)
    {
        cout << myQ->arr[i] << " ";
    }
}

int main()
{
    Queue *myQ = new Queue(5);
    cout << "Is Empty: " << myQ->isEmpty() << endl;

    myQ->enqueue(1);
    myQ->enqueue(2);
    myQ->enqueue(3);
    myQ->enqueue(4);
    myQ->enqueue(5);

    printQ(myQ);
    cout << endl;

    cout << "Is Full: " << myQ->isFull() << endl;

    myQ->dequeue();
    myQ->dequeue();

    printQ(myQ);
    cout << endl;

    cout << "Front  is : " << myQ->getFront() << endl;
    cout << "Rear  is : " << myQ->getRear() << endl;
}
