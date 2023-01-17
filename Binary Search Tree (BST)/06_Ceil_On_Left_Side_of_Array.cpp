/*
Given an array of integers, find the closest greater element for every element at left side of array.
If there is no greater element then print -1

Input : arr[] = {2, 8, 30, 15, 25, 12}
Output : -1 -1 -1 30 30 15
*/

#include <bits/stdc++.h>
using namespace std;

void ceilOnLeftSide(int arr[], int n)
{
    cout << -1 << " ";

    set<int> s;
    for (int i = 1; i < n; i++)
    {
        if (s.lower_bound(arr[i]) != s.end())
        {
            cout << *s.lower_bound(arr[i]) << " ";
        }
        else
        {
            cout << -1 << " ";
        }

        s.insert(arr[i]);
    }
}

int main()
{

    int arr[] = {2, 8, 30, 15, 25, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    ceilOnLeftSide(arr, n);
}