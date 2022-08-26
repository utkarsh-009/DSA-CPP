/*
    I/P: "ab"
    O/P: "", "a", "b","ab"
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Example "ab"
    Counters (2^2 => 4 counters): 00, 01, 10, 11
    -> 00 => ""
    -> 01 -> "a"
    -> 10 -> "b"
    -> 11 -> "ab"
*/

// Using Bitwise and Left Shift [TC: O(2^n*n), AS: O(1)]
void printPowerSet(string str)
{
    int n = str.length();
    int powsize = pow(2, n);

    for (int counter = 0; counter < powsize; counter++) // Iterating over all the binary counters till no of possible powerset
    {
        // Printing the powerset
        for (int i = 0; i < n; i++) // Iteration over string to check whether bit is set or not
        {
            if ((counter & (1 << i)) != 0) // If the ith bit is set then we print the ith character of string
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
}

int main()
{

    string str = "abc";

    printPowerSet(str);
}