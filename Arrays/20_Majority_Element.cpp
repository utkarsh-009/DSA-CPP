/*
    I/P: {8,3,4,8,8}
    O/P: 8

    I/P: {3,7,4,7,7,5}
    O/P: -1
*/

#include <bits/stdc++.h>
using namespace std;

// Moore's Voting Algorithm [TC: O(n), AS: O(1)]
int majorityElement(int arr[], int n)
{
    int count = 1;
    int majority = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (majority == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count <= 0)
        {
            count = 1;
            majority = arr[i];
        }
    }

    return majority;
}

int main()
{
    int arr[] = {8, 3, 4, 8, 8}, n = 5;

    cout << majorityElement(arr, n);
}
