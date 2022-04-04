#include <bits/stdc++.h>
using namespace std;

int binSearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
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

int main()
{

    int arr[] = {34, 21, 67, 5, 3, 17, 97, 23};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << binSearch(arr, n, 17) << endl;

    cout << binSearch(arr, n, 27);
}