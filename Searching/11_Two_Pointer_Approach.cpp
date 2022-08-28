/*
    I/P: {2,5,8,12,30}, sum = 17
    O/P: True (5,12)

    I/P: {2,5,8,12,30}, sum = 11
    O/P: False

Find pair in sorted array which gives sum X
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: ,AS:]
bool isPresent(int arr[], int n, int sum)
{
    int low = 0, high = n - 1, pairSum = 0;

    while (low <= high)
    {
        pairSum = arr[low] + arr[high];
        if (pairSum == sum)
        {
            return true;
        }
        else if (pairSum > sum)
        {
            high--;
        }
        else if (pairSum < sum)
        {
            low++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 11;

    cout << isPresent(arr, n, sum);
}