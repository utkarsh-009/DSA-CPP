#include <bits/stdc++.h>
using namespace std;

/*
NOTE:
-> Compier by default creates copy constructor that assigns member of one class to another class
*/

// Shallow Copy
class Test
{
    int *ptr;

public:
    Test(int x)
    {
        ptr = new int(x); // New memory allocation to store integer x
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
    /* Shallow Copy: Pointers, Address Value is copied as it is. Also, New Memory is not allocated  */
    Test t1(10);
    Test t2(t1); // Shallow Copying of t1 to t2

    t1.print();
    t2.print();

    t2.set(20); // Value of t2 changes => Value of t1 also changes due to Shallow Copy

    t1.print();
    t2.print();
}
