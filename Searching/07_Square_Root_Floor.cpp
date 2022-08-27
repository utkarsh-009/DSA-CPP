/*
    I/P: x = 4
    O/P: 2

    I/P: x = 14
    O/P: 3

Given an integer, we need to find floor of its square root.
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient [TC: O(logn),AS: O(1)]
int sqRootFloor(int x)
{
    int low = 1, high = x, ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midSquare = mid * mid;

        if (midSquare == x) // Perfect Square case
        {
            return mid;
        }
        else if (midSquare > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid; // Storing the last occurence s.t. midSquare < x
        }
    }

    return ans;
}

int main()
{
    cout << sqRootFloor(10);

    return 0;
}
