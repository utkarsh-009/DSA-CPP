#include <bits/stdc++.h>
using namespace std;

//Constructors are called whenever object is created
class Point
{
private:
    int x, y;

public:
    Point() // Constructor With Default Initialiser
    {
        x = 0;
        y = 0;
    }

    Point(int x1, int y1) // Constructor With Custom Initialiser
    {
        x = x1;
        y = y1;
    }

    void print() // print member function
    {
        cout << x << " " << y << endl;
    }
};

int main()
{
    Point p1; // Creating Object without giving initial values (uses default value used in constructor definition)
    p1.print();

    Point p2(6, 4); // Creating Object with giving initial values
    p2.print();

    Point *ptr = new Point(5, 10); // Creating a Pointer which points to the object type of Point
    ptr->print();                  // Accessing member function using pointer
}
