/*
Matrix Chain Multiplication:
Given a sequence of matrices, find the most efficient way to multiply these matrices together.
The efficient way is the one that involves the least number of multiplications.

I/P: arr[] = {2,1,3,4} i.e. M1 = 2*1, M2 = 1*3, M3 = 3*4
Output: 20
Explaination: minimum computation reqd => ((M1)*(M2*M3)). In ((M1)*(M2*M3)) computation cost for each partition is,
M2*M3 => 1*3*4 => 12
M1*(M2*M3) => 2*(Dimensions of M2*M3) => 2*1*4 => 8
Total Cost => 12 + 8 = 20
*/

#include <bits/stdc++.h>
using namespace std;

/*
NOTE: arr[] = {2,1,3,4}, N = 4 => M1 = 2*1, M2 = 1*3, M3 = 3*4
1.) How computations are done
If M1 = 2*1, M2 = 1*3, M3 = 3*4,
Computation cost require for => M1*M2 = 2*(Dimesions of M2) = 2*1*3 = 6, M2*M3 = 2*(Dimesions of M2) = 1*3*4 = 6

2.) How partitions are done
M1 = 2*1, M2 = 1*3, M3 = 3*4
=> When partitions done where ((M1)*(M2*M3)) => We divide array into {2,1}{1,3,4} to retain dimensions of both M1 and M2
after partioning.
*/
// [TC: O(N*N*N), AS: O(N*N)]
int MCMmemo(int arr[], int start, int end, vector<vector<int>> &dp)
{
    // No more partition can be made as only one element is left
    if (start + 1 == end)
        return 0;

    // Already precomputed partition
    if (dp[start][end] != INT_MAX)
        return dp[start][end];

    // Considering every partition to find least number of multiplications.
    for (int mid = start + 1; mid < end; mid++)
    {
        int p1 = MCMmemo(arr, start, mid, dp);
        int p2 = MCMmemo(arr, mid, end, dp);
        int curr_cost = arr[start] * arr[mid] * arr[end];
        dp[start][end] = min(dp[start][end], p1 + p2 + curr_cost);
    }

    return dp[start][end];
}

// [TC: O(N*N*N), AS: O(N*N)]
int MCMtab(int arr[], int N)
{
    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));

    // Partition size/Gap size 1 => Cost req = 0
    for (int i = 0; i < N - 1; i++)
        dp[i][i + 1] = 0;

    // For other gaps
    for (int gap = 2; gap < N; gap++)
    {
        for (int start = 0; start + gap < N; start++)
        {
            int end = start + gap;
            for (int mid = start + 1; mid < end; mid++)
            {
                int p1 = dp[start][mid];
                int p2 = dp[mid][end];
                int cost = arr[start] * arr[mid] * arr[end];
                dp[start][end] = min(dp[start][end], p1 + p2 + cost);
            }
        }
    }

    /*
    dp[0][N-1] => This value represents the minimum number of scalar multiplications needed to multiply all the
    matrices from the first matrix (matrix 1) to the last matrix (matrix N-1).
    */
    return dp[0][N - 1];
}

int main()
{
    int arr[] = {2, 1, 3, 4}, N = 4;
    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    cout << MCMmemo(arr, 0, N - 1, dp);
}