/*
    I/P: {0,0,0,1,1,1}, n = 6
    O/P: 3

    I/P: {0,0,0,0}, n = 4
    O/P: 0
*/

#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int x)
{
    int l = 0, h = n - 1, mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                h = mid - 1;
            }
        }
    }

    return -1;
}

// Iterative [TC: O(logn),AS: O(1)]
int count1sOcc(int arr[], int n)
{
    int first = firstOcc(arr, n, 1);
    return ((first != -1) ? n - first : 0);
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1}, n = 6;

    cout << count1sOcc(arr, n);
}
