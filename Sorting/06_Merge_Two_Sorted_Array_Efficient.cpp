#include <bits/stdc++.h>
using namespace std;

//No need to use extra array or copy elements in that extra array
//Time Complexity: O(nlogn) or O(mlogm) 
//Space Complexity: O(1)
void effMergeSort2Arr(int a[], int b[], int m, int n)
{
    //Array a and b are sorted initially
    sort(a, a + m);
    sort(b, b + n);

    int i = 0, j = 0;

    //We will compare elements of array a and b until one of the array's all elements are finished comparing with other
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[j] << " ";
            j++;
        }
    }

    //Now the array whose elements are yet to be merged, will be merged directly as array is initally sorted
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << b[j] << " ";
        j++;
    }
}

int main()
{
    int a1[] = {34, 64, 82, 1, 3, 7, 44, 200};
    int a2[] = {2, 25, 7, 6, 68, 1000};

    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    effMergeSort2Arr(a1, a2, n1, n2);
}