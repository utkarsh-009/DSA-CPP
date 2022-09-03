/*
    I/P: {10, 10, 20, 30, 30, 30}, n = 6
    O/P: 10 2
         20 1
         30 3
*/

#include <bits/stdc++.h>
using namespace std;

// Implementation IMP [TC: O(n), AS: O(1)]
void printFreqInSortedArr(int arr[], int n)
{
    int freq = 1, i = 1;

    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }

        cout << arr[i - 1] << " " << freq << endl;

        i++;
        freq = 1;
    }
}

int main()
{
    int arr[] = {10, 10, 20, 30, 30, 30}, n = 6;

    printFreqInSortedArr(arr, n);
}
