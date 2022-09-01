#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        //'this' pointer is a constant pointer that holds memory address of current object
        this->x = x; // this->x  => object's x
        this->y = y; // this->y => object's y
    }

    // this pointer can also be used to change functions
    Point &setX(int x)
    {
        this->x = x;
        return *this; // returns pointer of current object
    }

    Point &setY(int y)
    {
        this->y = y;
        return *this; // returns pointer of current object
    }

    void print()
    {
        cout << this->x << " " << this->y;
    }
};

int main()
{
    Point p1(10, 35);
    p1.setX(5).setY(5); // Chaining can be attained using this pointer

    p1.print();
    return 0;
}
