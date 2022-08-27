#include <bits/stdc++.h>
using namespace std;

// If i < j && arr[i] > arr[j] => Count Inversion
// Time complexity: O(n^2)
int naiveCountInversion(int arr[], int n)
{
    int cnt = 0; // To count no of count inversion
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        for (int j = i; j < n; j++)
        {
            if (x > arr[j]) // Comparing to know whether the sequence is count inversion or not
            {
                cnt++;
            }
        }
    }
    return cnt; // returning no of count inversion
}

int main()
{

    int arr[] = {2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << naiveCountInversion(arr, n);
}