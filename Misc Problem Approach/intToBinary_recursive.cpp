// Recursive approach:
#include <iostream>
using namespace std;

void bin(unsigned n)
{
    if (n > 1)
    {
        bin(n / 2);
    }

    cout << n % 2;
}

int main()
{
    int a = 5;
    bin(a);
}