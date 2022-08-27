#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O[(m+n)log(m+n)]
//Space Complexity: O(m+n)
void naiveMergeSort2Arr(int a[], int b[], int m, int n)
{
    int c[m + n]; // Defining array of size m + n, as it will store merged and sorted elements of array a & b

    for (int i = 0; i < m; i++)
    {
        c[i] = a[i]; // Copying elements of array a in array c
    }

    for (int j = 0; j < n; j++)
    {
        c[m + j] = b[j]; // Copying elements of array b after copying elements of a
    }

    sort(c, c + m + n); // After copying all elements of a and b, we will sort array

    for (int i = 0; i < m + n; i++)
    {
        cout << c[i] << " "; // Printing elements of c, after merging and sorting
    }
}

int main()
{
    int a1[] = {34, 64, 82, 1, 3, 7, 44, 200};
    int a2[] = {2, 25, 7, 6, 68, 1000};

    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    naiveMergeSort2Arr(a1, a2, n1, n2);
}