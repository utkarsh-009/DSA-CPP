/*
    I/P: n = 5, a = 5, b = 2, c = 1
    O/P: 5 (5 pieces of length 1)

    I/P: n = 23, a = 12, b = 9, c = 11
    O/P:2 (1 piece of length 12 and 1 piece of length -1)

    I/P: n = 5, a = 4, b = 2, c = 6
    O/P: -1

    Cutting Rope only of given lengths  such that number of peices are maximum
*/

#include <bits/stdc++.h>
using namespace std;

// [TC: O(3^n),AS: O(3^n)]
int maxPieces(int n, int a, int b, int c)
{
    // Base Case
    if (n == 0) // Rope Cut Possible
    {
        return 0;
    }

    if (n <= -1) // Rope Cut Not Possible
    {
        return -1;
    }

    int res = max(maxPieces(n - a, a, b, c), max(maxPieces(n - b, a, b, c), maxPieces(n - c, a, b, c))); // result stores max of all three

    if (res == -1) // If max of all three is -1 => No rope cutting possible
    {
        return -1;
    }

    return res + 1; // Adds 1 to result from base case until the main caller
}

int main()
{
    int n = 5, a = 2, b = 1, c = 5;
    // int n = 5, a = 4, b = 2, c = 6;

    cout << maxPieces(n, a, b, c);

    return 0;
}
