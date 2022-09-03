/*
    I/P: arr[] = {3, 8, 12, 5, 6}, n = 5
    O/P: {6, 5, 12, 8, 3}

*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
void revArray(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

int main()
{
    int arr[] = {10, 5, 7, 30}, n = 4;

    cout << "Before Reverse" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    revArray(arr, n);

    cout << "After Reverse" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
