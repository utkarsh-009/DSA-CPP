#include <bits/stdc++.h>
using namespace std;

// Deep Copy
class Test
{
    int *ptr;

public:
    Test(int x)
    {
        ptr = new int(x); // New memory allocation to store integer x
    }

    Test(const Test &t) // When initialised using object of same class
    {
        int val = *(t.ptr); // Storing value of that object in a variable
        ptr = new int(val); // Creating new memory and storing variable value in it
    }

    void set(int x)
    {
        *ptr = x;
    }

    void print()
    {
        cout << *ptr << endl;
    }
};

int main()
{
    /* Deep Copy: New Pointers, Address Value are created using new memory allocation. */
    Test t1(10);
    Test t2(t1); // Deep Copying of t1 to t2

    t1.print();
    t2.print();

    t2.set(20); // Value of t2 changes => Value of t1 doesnt changes due to Deep Copy. They are stored in two different memory location

    t1.print();
    t2.print();
}
