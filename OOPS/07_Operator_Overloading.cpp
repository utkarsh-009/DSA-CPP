#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        this->real = r;
        this->imag = i;
    }

    Complex operator+(const Complex &c)
    {
        Complex ans;
        ans.real = this->real + c.real;
        ans.imag = this->imag + c.imag;

        return ans;
    }

    Complex operator-(const Complex &c)
    {
        Complex ans;
        ans.real = this->real - c.real;
        ans.imag = this->imag - c.imag;

        return ans;
    }

    void print()
    {
        cout << this->real << " " << this->imag << endl;
    }
};

int main()
{
    Complex c1(2, 4), c2(5, 2);
    auto sum = c1 + c2;
    auto diff = c1 - c2;

    sum.print();
    diff.print();
}
