#include <bits/stdc++.h>
using namespace std;

// Constructors are called whenever object is created
// Destructors are called whenever object is destroyed

/*
NOTE: Destructors are also created by Default. Hence, we have to write destructor when we are dynamically
allocating the memory. If we do not write destructor, then memory will never be deallocated
*/
class Test1
{
public:
    Test1() { cout << "Test1 Constructor Called" << endl; }
    ~Test1() { cout << "Test1 Destructor Called" << endl; }
};

class Test2
{
    int x;

public:
    Test2(int i) : x(i)
    {
        cout << "Test2 Constructor Called" << endl;
    }

    ~Test2()
    {
        cout << "Test2 Destructor Called" << endl;
    }
};

int main()
{
    Test1 t;

    Test2 t1(23);
    Test2 t2(35);
    return 0;
}
