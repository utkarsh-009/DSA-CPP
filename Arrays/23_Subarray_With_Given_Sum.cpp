/*
Note: There are no negative elements
    I/P: [1,4,20,3,10,5], sum = 33
    O/P: Yes

    I/P: [2,4], sum = 3
    O/P: No
*/

#include <bits/stdc++.h>
using namespace std;

// Using Sliding Window  [TC: O(n), AS: O(1)]
/*
We are adding and removing an element from window atmost once.
Adding takes O(1) and Removing takes O(1) => Total Time: O(2*n) => O(n)
*/
bool isSubarraySum(int arr[], int n, int sum)
{
    int curr_sum = 0;
    int start = 0;

    for (int end = 0; end < n; end++)
    {
        curr_sum += arr[end];

        while (curr_sum > sum)
        {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[] = {1, 4, 20, 3, 10, 5}, n = 6, sum = 33;

    cout << isSubarraySum(arr, n, sum);
}
