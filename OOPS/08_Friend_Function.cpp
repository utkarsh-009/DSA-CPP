#include <bits/stdc++.h>
using namespace std;

// Friend Function
class Employee; // Declaring class employee

class Printer // Declaring class printer and its function
{
public:
    void printEmp(const Employee &e);
};

class Employee
{
private: // id, name are set as private data members
    int id;
    string name;

public:
    // Here, printEmp function of class Printer is declared as friend function which will allow to access private data members of employee class
    friend void Printer ::printEmp(const Employee &e);
    Employee(int i, string n) : id(i), name(n) {}
};

// Defining function definition
void Printer::printEmp(const Employee &e)
{
    cout << e.id << " " << e.name << endl;
}

int main()
{
    Printer p;
    Employee e(101, "ABC");
    p.printEmp(e);
    return 0;
}
