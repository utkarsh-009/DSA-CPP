/*
    I/P: arr[] = {3, 8, 12, 5, 6}, n = 5
    O/P: 8
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
int find2ndLargest(int arr[], int n)
{
    int first = 0, second = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < first && arr[i] > second)
        {
            second = arr[i];
        }
    }

    return second;
}

int main()
{
    int arr[] = {3, 8, 12, 5, 6}, n = 5;

    cout << "Second Largest Element in Array: " << find2ndLargest(arr, n);
}
