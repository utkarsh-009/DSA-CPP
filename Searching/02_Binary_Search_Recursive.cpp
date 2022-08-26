#include <bits/stdc++.h>
using namespace std;

// [TC: O(logn), AS: O(logn)]
int binSearch(int arr[], int low, int high, int x)
{
    // As low is either increasing or high is decreasing after every recursive call. Hence, at some point incase of unsuccesful search low > high
    if (low > high) // base condition for unsuccessful search.
    {
        return -1; // return -1 as a indication for unsuccessul search
    }

    int mid = low + (high - low) / 2; // define mid in this manner instead of mid = (high + low)/2 as to prevent overflow

    if (arr[mid] == x) // if element is found, return its index
    {
        return mid;
    }
    else if (arr[mid] > x) // if mid element of array is greater than x(the integer to be searched), decrease high to mid - 1 i.e. high = mid - 1;
    {
        return binSearch(arr, low, mid - 1, x);
    }
    else // if mid element of array is smaller than x(the integer to be searched), increase low to mid + 1 i.e. low = mid + 1;
    {
        return binSearch(arr, mid + 1, high, x);
    }
}

int main()
{

    int arr[] = {34, 21, 67, 5, 3, 17, 97, 23};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << binSearch(arr, 0, n - 1, 17) << endl;
    cout << binSearch(arr, n, 27);
}