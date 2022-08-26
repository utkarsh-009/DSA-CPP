#include <iostream>
#include <algorithm>
using namespace std;

// [TC: O(logn), AS: O(1)]
int binSearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    // After every iteration, the length between high and low will decrease.
    // At some point, when given element is not to be found then the low will be either greater or equal to the high. This is where we break out of loop
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // To avoid overflow
        if (arr[mid] == x)
        {
            return mid; // if element is found, return its index
        }
        else if (arr[mid] > x)
        {
            // if mid element of array is greater than x(the integer to be searched),then decrease high to mid - 1 i.e. high = mid - 1;
            high = mid - 1;
        }
        else
        {
            // if mid element of array is smaller than x(the integer to be searched), then increase low to mid + 1 i.e. low = mid + 1;
            low = mid + 1;
        }
    }
    return -1;
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

    cout << binSearch(arr, n, 17) << endl;

    cout << binSearch(arr, n, 27);
}