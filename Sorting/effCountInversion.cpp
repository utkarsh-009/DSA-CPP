#include <bits/stdc++.h>
using namespace std;

int countAndMerge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[n1 + j];
    }

    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[i])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res = res + (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

int effCountInversion(int arr[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += effCountInversion(arr, l, m);
        res += effCountInversion(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{

    int arr[] = {2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << effCountInversion(arr, 0, n - 1);
}