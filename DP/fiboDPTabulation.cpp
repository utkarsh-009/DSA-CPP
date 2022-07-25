#include <iostream>
#include <vector>
using namespace std;

// TABULATION TECHNIQUE (BOTTOM UP APPROACH)
//  Time Complexity : O(n)
//  Space Complexity : O(n)

// 0 1 1 2 3 5 8 13 21 34 55 89....

int fiboDP(int n)
{
    vector<int> table(n + 1); // Creating a table of size n+1

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
    cout << fiboDP(10); // number present at index 10 in fibonacci sequence
}