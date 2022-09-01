#include <bits/stdc++.h>
using namespace std;

class Person // Base Class/ Super Class
{
protected: // proctected access specifier is not accessible outside the class but accessible for derived classes/ inherited class/ sub-class
    string name;
    int id;

public:
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

class Student : public Person // Derived Class
{
private:
    int marks;

public:
    Student(string n, int i, int m) : Person(n, i), marks(m) // name and id are initialised using Person class, while marks are initialised using Student class
    {
    }

    void print()
    {
        cout << id << " " << name << "  " << marks << endl;
    }
};

int main()
{
    Student s1("Utkarsh Patil", 201080034, 100);

    s1.print();
}
