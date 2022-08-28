/*
    I/P: {1, 10, 15, 20, 40, 80, 100,......}, x = 100
    O/P: 7
*/

#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int low, int high)
{
    int mid = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Unbounded Binary Search  [TC: log(pos) ,AS: O(1)], pos is position of element x
int search(int arr[], int x)
{
    if (arr[0] == x)
    {
        return 0;
    }

    int i = 1;
    while (arr[i] < x)
    {
        i *= i;
    }

    if (arr[i] == x)
    {
        return i;
    }

    return binSearch(arr, i / 2 + 1, i - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 5, 5};
    int x = 4;

    cout << search(arr, x);

    return 0;
}
