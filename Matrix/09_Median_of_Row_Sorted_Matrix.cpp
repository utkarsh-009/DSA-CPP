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

// Efficient Using Binary Search [TC: O(R*log(max-min)*logC)]
int matMedEff(int mat[][MAX], int R, int C)
{
    // Finding min and max element in matrix
    int min = mat[0][0], max = mat[0][C - 1];
    for (int i = 0; i < R; i++)
    {
        if (min < mat[i][0])
        {
            min = mat[i][0];
        }
        if (max > mat[i][C - 1])
        {
            max = mat[i][C - 1];
        }
    }

    int medPos = (R * C + 1) / 2; // Position of median will be in middile of all elements => (Total no of elements)/2

    /*
    // Binary Search
        For a number to be median, there should be exactly (n/2) numbers which are less than this number
        => mid : Candidate for median
        => midPos : No of elements smaller than mid
        => medPos : The actual no of elements that should be less than median
    */

    while (min < max)
    {
        int mid = (min + max) / 2; // Candidate for median
        int midPos = 0;

        // Finding count of elements smaller than mid
        for (int i = 0; i < R; i++)
        {
            midPos += upper_bound(mat[i], mat[i] + C, mid) - mat[i];
        }
        if (midPos < medPos) // The candidate is smaller than median
        {
            min = mid + 1;
        }
        else // candidate is equal to or greater than median
        {
            max = mid;
        }
    }
    return min; // min stores median of matrix
}

int main()
{
    int m[][MAX] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    // int m[][MAX] = {{5, 10, 20, 30}, {1, 2, 3, 4}, {11, 13, 15, 17}};
    cout << "Median is " << matMedNaive(m, 3, 5) << endl;
    cout << "Median is " << matMedEff(m, 3, 5) << endl;
}

/*
I/P: 5 10 20 30 40
     1  2  3  4  6
     11 13 15 17 19
    (1,2,3,4,5,6,10,*11*,13,15,17,19,20,30,40)
O/P: 11

Dry Run:
medPos = (3*5 + 1)/2 = (16)/2 = 8

min= 1, max = 40
mid = 20
midPos = 3 + 5 + 5 = 13 (medPos < midPos) => max = mid

min = 1, max = 20
mid = 10
midPos = 2 + 5 + 0  = 7 (medPos > midPos) => min = mid + 1

mid = 11, max = 20
mid = 15
midPos = 2 + 5 + 3 = 10 (medPos < midPos) => max = mid

min = 11, max = 15
mid = 13
midPos = 2 + 5 + 2 = 9 (medPos < midPos) => max = mid

min = 11, max = 13
mid = 12
midPos = 2 + 5 + 1 = 8 (medPos = midPos) but (min != max) and 12 not present in matrix

min = 11, max = 12
mid = 11
midPos = 2 + 5 + 1 = 8 (medPos = midPos)

min = 11 and max = 11
*/