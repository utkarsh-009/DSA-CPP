#include <iostream>
using namespace std;

// TABULATION TECHNIQUE (BOTTOM UP APPROACH)
//  Time Complexity : O(n)
//  Space Complexity : O(n)
int fiboDP(int n)
{

    int table[n + 1]; // Creating a table of size n+1

    table[0] = 0, table[1] = 1; // Base Values

    // Storing all values inside table
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }

    // Returning value of nth fibonacci number
    return table[n];
}

int main()
{
    cout << fiboDP(5);
}