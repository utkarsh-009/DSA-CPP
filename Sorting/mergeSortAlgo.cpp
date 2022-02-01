#include <bits/stdc++.h>
using namespace std;

//merge function to merge two sorted sub arrays into whole sorted array
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + low];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        arr[k] = right[i];
        j++;
        k++;
    }
}

int main()
{
    //merge function
    int a[] = {5, 8, 12, 14, 7};
    merge(a, 0, 3, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}