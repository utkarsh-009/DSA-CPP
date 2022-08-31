/*
    I/P: {4, 2, 1, 3, 2, 2}
    O/P: 2

    I/P: {1, 2, 3, 3, 4, 5}
    O/P: 3

Range of Element => 0 <= max(arr) <= n-1, n = size of array
Only One Element repeats, FIND THE REPEATING ELEMENT without MODIFICATION OF INPUT ARRAY
*/

#include <bits/stdc++.h>
using namespace std;

// Using Boolean Array [TC: O(n),AS: O(n)]
int repeated(int arr[], int n)
{
    bool visited[n - 1];
    for (int i = 1; i < n; i++)
    {
        if (visited[arr[i]])
        {
            return arr[i];
        }
        visited[arr[i]] = 1;
    }

    return -1;
}

int main()
{

    int arr[] = {4, 2, 1, 3, 2, 2}, n = 6;

    cout << repeated(arr, n) << endl;
    return 0;
}
