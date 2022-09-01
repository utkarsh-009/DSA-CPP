#include <bits/stdc++.h>
using namespace std;

class Complex
{
private: // private variables
    int real;
    int imag;

public: // public member functions
    void print()
    {
        cout << real << " + i" << imag << endl;
    }

    Complex(int r, int i) // Constructor for intialising
    {
        real = r;
        imag = i;
    }
};

int main()
{
    Complex c1(10, 15);
    c1.print();
}
