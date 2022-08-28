/*
    I/P: {2,3,4,8,9,20,40}, sum = 32
    O/P: True (20 + 8 + 4)

Find triplet in an array which gives sum X
*/

#include <bits/stdc++.h>
using namespace std;

// Using Two Pointer [TC: O(n*n),AS: O(1)]
bool isEqualToTriplet(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 3; i++)
    {
        int req_pair_sum = sum - arr[i]; // Find pair sum possible or not using two pointer

        int low = 0, high = n - 1, pairSum = 0;
        while (low <= high)
        {
            pairSum = arr[low] + arr[high];
            if (pairSum == req_pair_sum)
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
    }
    return false;
}

int main()
{
    int A[] = {2, 3, 4, 8, 9, 20, 40};
    int sum = 32;
    int arr_size = sizeof(A) / sizeof(A[0]);

    cout << isEqualToTriplet(A, arr_size, sum);

    return 0;
}
