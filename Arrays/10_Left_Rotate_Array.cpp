/*
    I/P: arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2
    O/P: {3, 4, 5, 1, 2}
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*d), AS: O(1)], d => Left Rotating Array by 'd' places
void leftRotateBy1(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

void leftRotateNaive(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
    {
        leftRotateBy1(arr, n);
    }
}

// Using Reversal Algorithm [TC: O(n), AS: O(1)]
void reverse(int arr[], int low, int high) // Reversing the Sub-Array
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    reverse(arr, 0, d - 1); // Reversing from 0 to d-1
    reverse(arr, d, n - 1); // Reversing from d to n-1
    reverse(arr, 0, n - 1); // Reversing from 0 to n-1
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2;

    printf("Before Rotation \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    leftRotate(arr, n, d);

    printf("After Rotation \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
