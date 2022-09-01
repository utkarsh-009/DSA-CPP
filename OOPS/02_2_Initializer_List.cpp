#include <bits/stdc++.h>
using namespace std;

/*
NOTE: Initialiser List has better performance than Normal Constructor
=> First class members are initialised with some values, then Constructor Body is executed.
In initialiser we intialise members only once, but in Normal Constructor where the values are initalised with some default value
and then value initialised in the construtor body.
*/

class Point
{
private:
    int x, y;

public:
    // Initializer List Using Default Values
    Point() : x(0), y(0)
    {
    }

    // Initializer List Using User Defined Values
    Point(int x1, int y1) : x(x1), y(y1)
    {
    }

    void print()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{
    Point p1;
    p1.print();

    Point p2(5, 1);
    p2.print();

    Point *ptr = new Point(5, 2);
    ptr->print();
}
