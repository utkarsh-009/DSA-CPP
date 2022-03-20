// Iterative approach: To iterate through all bits from Most Significant Bit to Least Significant Bit
#include <iostream>
using namespace std;

void bin(unsigned n)
{
    unsigned i;
    // Left Shit 1 by 31 bits i.e. 00000000000000000000000000000001 to 10000000000000000000000000000000
    for (i = 1 << 31; i > 0; i = i / 2) //
    {
        if ((n & i) != 0) // in each iteration, the position of set bit in the integer i checks the corresponding bit int the given integer
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
}

int main()
{
    int a = 1;
    bin(a);
}