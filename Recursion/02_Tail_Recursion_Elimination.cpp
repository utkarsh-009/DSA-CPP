/*
    I/P: 4
    O/P: 1 2 3 4
To remove tail call recursion we use goto function.
*/

#include <bits/stdc++.h>
using namespace std;

//  1 to N [TC: O(n),AS: O(n)] (Tail Recursion + Recursion Call Stack)
void print1toN(int n)
{
    if (n == 0)
    {
        return;
    }

    print1toN(n - 1);
    cout << n << " ";
}

//  1 to N [TC: O(n),AS: O(1)] (No Tail Call Recursion + No Recursion Call Stack)
void print1toNOptimised(int n, int k)
{
start:
    if (n == 0)
    {
        return;
    }
    cout << k << " ";
    n = n - 1;
    k = k + 1;
    goto start;
}

// N to 1 [TC: O(n),AS: O(n)] (No Tail Recursion + Recursion Call Stack)
void printNto1(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    print1toN(n - 1);
}

//  1 to N [TC: O(n),AS: O(1)] (No Tail Recursion + No Recursion Call Stack) [Modern Compilers by default modify printNto1 to printNto1Optismised so as to eliminate Recursion Call Stack]
void printNto1Optimised(int n)
{
start:
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    n = n - 1;
    goto start;
}

int main()
{
    int n = 4;
    printNto1Optimised(n);
    cout << endl;
    print1toNOptimised(n, 1);
}
