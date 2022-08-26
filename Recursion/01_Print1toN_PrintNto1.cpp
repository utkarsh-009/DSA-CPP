/*
    I/P: 4
    O/P: 1 2 3 4
         4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

//  1 to N [TC: O(n),AS: O(n)] (Tail Call Recursion)
void print1toN(int n)
{
    if (n == 0)
    {
        return;
    }

    print1toN(n - 1);
    cout << n << " ";
}

// N to 1 [TC: O(n),AS: O(n)] (No Tail Call Recursion)
void printNto1(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    print1toN(n - 1);
}

int main()
{
    int n = 4;
    print1toN(n);
    cout << endl;
    printNto1(n);
}
