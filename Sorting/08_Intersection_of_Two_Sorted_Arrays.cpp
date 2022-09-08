/*
    I/P: a[] = {3,5,10,10,10,10,15,15,20}
         b[] = {5,10,10,15,30}
    O/P: 5 10 15
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*m), AS: O(1)]
void intersectionNaive(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i > 0 && a[i] == a[i - 1]) // if a[i] = a[i-1] => element is repeatitive
        {
            continue; // we will only check for last occurence of repeatitive element, if present in 2nd array or not
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j]) // a[i] comes under Intersection
            {
                cout << a[i] << " ";
                break;
            }
        }
    }
}

// Efficient [TC: O(m+n), AS: O(1)]
void intersectionEff(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) //  we will compare one array element with other array element
    {
        // If there are more than one elements with same value, we will consider only the first and ignore other equal value elements
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }

        // Comparing elements of two array
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }

        // This condition is when a[i] == b[j], which will be the intersection between two array
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    intersectionEff(a, b, m, n);
}
