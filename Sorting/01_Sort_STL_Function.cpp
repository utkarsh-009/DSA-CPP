#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {34, 21, 67, 5, 3, 17, 97, 23};

    int n = sizeof(arr) / sizeof(arr[0]); // Length 'n' upto which we want to sort array is defined in this manner
    // This 'n' will be used to get iterator of element after last element

    sort(arr, arr + n); // Ascending order sort

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    sort(arr, arr + n, greater<int>()); // Descending order sort, third parameter greater<E>() must be given with generic type E

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Similarly works for char
    char a[] = {'d', 'a', 't', 'u', 'z'};
    int n1 = sizeof(a) / sizeof(a[0]); // Size of array is calculated in this manner

    sort(a, a + n1);
    for (int i = 0; i < n1; i++)
    {
        cout << a[i] << " ";
    }
}