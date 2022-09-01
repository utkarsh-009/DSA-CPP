#include <bits/stdc++.h>
using namespace std;

/*
Diamond Problem: Java doesnt allow Multiple Inheritance
        -> B
    A -      -> D
        -> C
*/

// Diamond Problem
class A
{
public:
    int x;

    A()
    {
        x = 0;
    }
};

class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    cout << d.x;
}
