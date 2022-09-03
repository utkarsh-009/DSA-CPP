/*
    I/P: arr = {5,24,64,2,7} , x = 64
    O/P: 2

    I/P: arr = {5,24,64,2,7} , x = 34
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n),AS: O(1)] => Best Case: Element Present At Begining, Worst Case: Element Not Present
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {20, 5, 7, 25}, x = 5;
    cout << search(arr, 4, x);
}
