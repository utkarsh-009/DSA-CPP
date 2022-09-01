#include <bits/stdc++.h>
using namespace std;

// Note: A base class type refernce or pointer can refer to a dervied class object
class Base
{
public:
    virtual void print() // virtual keyword used to decide constructer of object to which it is pointing, not to be decided using pointer type
    {
        cout << "Base \n";
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived \n";
    }
};

int main()
{
    Base b;
    b.print();

    Derived d;
    d.print();

    Base *ptr = &d;
    ptr->print();

    /*

    Before Using Virtual Keyword: Even if object assigned is of Derived Class, the Base class constructor was called because the pointer was of Base Class Data type
    O/P:
        Base
        Derived
        Base

    After Using Virtual Keyword: Using the Virtual Keyword in Base Class, the Dervied class constructor was called even if the pointer was of Base Class Data type
    O/P:
        Base
        Derived
        Derived
    */

    return 0;
}
