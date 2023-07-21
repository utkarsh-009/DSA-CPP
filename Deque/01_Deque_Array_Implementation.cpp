#include <iostream>
using namespace std;
// All O(1) operations
class Deque
{
public:
    int *arr;
    int front, rear, cap, size;

    // Deque constructor
    Deque(int c)
    {
        arr = new int[c];
        front = -1;
        rear = -1;
        size = 0;
        cap = c;
    }

    void pushFront(int x)
    {
        if (size >= cap)
        {
            cout << "Deque Full" << endl;
            return;
        }
        else
        {
            if (rear == -1)
                rear = 0;

            front = (front - 1 + cap) % cap;
            arr[front] = x;
            size++;
        }
    }

    void pushBack(int x)
    {
        if (size >= cap)
        {
            cout << "Deque Full" << endl;
            return;
        }
        else
        {
            if (front == -1)
                front = 0;

            rear = (rear + 1) % cap;
            arr[rear] = x;
            size++;
        }
    }

    void popFront()
    {
        if (size == 0)
        {
            cout << "Deque Empty" << endl;
            return;
        }
        else
        {
            front = (front + 1) % cap;
            size--;
        }
    }

    void popBack()
    {
        if (size == 0)
        {
            cout << "Deque Empty" << endl;
        }
        else
        {
            rear = (rear - 1 + cap) % cap;
            size--;
        }
    }

    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        return arr[rear];
    }

    void printDq()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Deque dq = Deque(5);
    dq.pushBack(10);  // 10
    dq.pushFront(20); // 20 10
    dq.pushFront(30); // 30 20 10
    dq.pushBack(40);  // 30 20 10 40
    dq.pushFront(50); // 50 30 20 10 40
    dq.printDq();
    dq.pushBack(60); // 50 30 20 10 40 60
}
