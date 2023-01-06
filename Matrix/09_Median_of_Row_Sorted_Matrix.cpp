#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Naive [TC: R*C*log(R*C)]
double matMedNaive(int mat[][MAX], int R, int C)
{
    vector<int> v;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            v.push_back(mat[i][j]);
        }
    }

    sort(v.begin(), v.end());
    int medPos = (R * C) / 2;

    return ((R * C % 2 != 0) ? v[medPos] : (double)(v[medPos] + v[medPos - 1]) / 2); // if case when total no of elements are even => v[medPos] and v[medPos - 1]
}

// Efficient Binary Search [ TC: O(R*log(max-min)*log(C)), AS: O(1) ]
// Intution: For a number to be median, there should be exactly (n/2) numbers which are less than this number

int upperBound(int matrix[][MAX], int R, int C, int mid) // To find number of elements less than given number
{
    int l = 0, h = C - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (matrix[R][m] <= mid)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    return l;
}

int matMedEff(int matrix[][MAX], int R, int C)
{
    // finding high and low i.e. minimum and maximum element in matrix
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        low = min(matrix[i][0], low);
        high = max(matrix[i][C - 1], high);
    }

    // For a number to be median, there should be exactly (n/2) numbers which are less than this number
    int desired = (R * C + 1) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int nums_less_than_mid = 0;

        // counting total number of elements that are less than mid
        for (int i = 0; i < R; i++)
        {
            nums_less_than_mid += upperBound(matrix, i, C, mid);
        }

        // if elments less than mid are less than desired => low = mid + 1
        if (nums_less_than_mid < desired)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    int m[][MAX] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    // int m[][MAX] = {{5, 10, 20, 30}, {1, 2, 3, 4}, {11, 13, 15, 17}};
    cout << "Median is " << matMedNaive(m, 3, 5) << endl;
    cout << "Median is " << matMedEff(m, 3, 5) << endl;
}
