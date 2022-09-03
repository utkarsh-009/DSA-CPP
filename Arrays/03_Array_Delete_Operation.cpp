/*
    I/P: arr[] = {3, 8, 12, 5, 6}, x = 12, n = 5
    O/P: {3, 8, 5, 6}
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int deleteElement(int arr[], int n, int x)
{
    int index = 0;
    for (int i = 0; i < n; i++) // Finding index of element that is to be deleted
    {
        if (arr[i] == x)
        {
            index = i;
            break;
        }
    }

    if (index == n) // Element not present for deletion
    {
        return n;
    }

    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return n - 1;
}

int main()
{
    int arr[] = {3, 8, 12, 5, 6}, x = 12, n = 5;

    cout << "Before Deletion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    n = deleteElement(arr, n, x);

    cout << "After Deletion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
