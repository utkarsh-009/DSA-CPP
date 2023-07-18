/*
Given a set of numbers, check whether it can be partitioned into two subsets such that
the sum of elements in both subsets is same or not.

Input: N = 4, arr[] = {1,5,11,5}
Output: YES
Explanation: There exists two subsets such that {1, 5, 5} and {11}.
*/

#include <bits/stdc++.h>
using namespace std;

/*
NOTE:
As the question states that array should be:
- broken down into two subsets
- sum of these two subsets should be equal
Hence, 2*(sum of a subset) = sum => sum of subset = sum/2
*/
bool findPartition(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum % 2)
    {
        return false;
    }

    // As we are checking if it possible to form sum/2 using given elements
    sum /= 2;
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 0; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int curr_sum = 1; curr_sum <= sum; curr_sum++)
        {
            dp[i][curr_sum] = dp[i - 1][curr_sum];

            // if a[i] <= curr_sum => we can check if current element when added can make possible to get curr_sum
            if (a[i - 1] <= curr_sum)
            {
                dp[i][curr_sum] = dp[i - 1][curr_sum] || dp[i - 1][curr_sum - a[i]];
            }
            //  we cannot add curr element => possibility of sum remains same as earlier
            else
            {
                dp[i][curr_sum] = dp[i - 1][curr_sum];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    int n = 4, a[] = {1, 5, 11, 5};
    (findPartition(a, n)) ? cout << "Possible" : cout << "Not Possible";
}