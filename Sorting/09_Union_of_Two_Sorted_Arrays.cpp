#include <bits/stdc++.h>
using namespace std;

void unionOf2UnsortedArray(int a[], int b[], int m, int n)
{
    // Initially sorting two given arrays
    sort(a, a + m);
    sort(b, b + n);

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1])
        {
            j++;
            continue;
        }

        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }

        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }

        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while (i < m)
    {
        if (i > 0 || a[i] != a[i - 1])
        {
            cout << a[i] << " ";
            i++;
        }
    }

    while (j < n)
    {
        if (j > 0 || b[j] != b[j - 1])
        {
            cout << b[j] << " ";
            j++;
        }
    }
}

int main()
{
    int a[] = {10, 30, 60, 20, 40};
    int b[] = {20, 2, 20, 30};

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    unionOf2UnsortedArray(a, b, m, n);
}