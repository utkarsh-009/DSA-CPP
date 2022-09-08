/*
    I/P: a[] = {3,5,10,10,10,10,15,15,20}
         b[] = {5,10,10,15,30}
    O/P: 3 5 10 15 20 30
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O((n+m)log(m+n)), AS: O(m+n)]
void unionNaive(int a[], int b[], int m, int n)
{
    int c[m + n]; // Auxillary array
    for (int i = 0; i < m; i++)
    {
        c[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        c[i + m] = b[i];
    }

    sort(c, c + m + n); // Sorting all elements
    for (int i = 0; i < m + n; i++)
    {
        if (i == 0 || c[i] != c[i - 1]) // if first element or two consecutive elements not equal => print element
        {
            cout << c[i] << " ";
        }
    }
}

// Efficient [TC: O(), AS: O()]
void unionEff(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i - 1]) // ignoring the repeatitive element in array a
        {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1]) // ignoring the repeatitive element in array b
        {
            j++;
            continue;
        }

        // printing the uncommon elements
        if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }

        else if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }

        else // a[i] == b[j]
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    // For remaining elements, print the repeatitive elements once
    while (i < m)
    {
        if (i > 0 && a[i] != a[i - 1])
        {
            cout << a[i] << " ";
        }
        i++;
    }

    while (j < n)
    {
        if (j > 0 && b[j] != b[j - 1])
        {
            cout << b[j] << " ";
        }
        j++;
    }
}

int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    unionEff(a, b, m, n);
}