#include <iostream>
using namespace std;
/*
*Dry Run*
arr = {5, 3, 8, 4, 2}; pivot = 5
i = -1 , j = 5

1st iter
i = 0, j = 4
5 < 5, F
2 > 5, F
swap i = 0, j = 4 => 2 3 8 4 5

2nd iter
i = 1, j = 3
3 < 5, T => i = 2; 8 < 5, F
4 > 5, F
swap i = 2, j = 3 => 2 3 4 8 5

3rd iter
i = 3, j = 2
8 < 5, F
4 > 5, F

O/P:
return j = 2;
2 3 4 8 5;
2,3 < 4 and 8,5 > 4
Here, arr[j = 2] is a new pivot which has: arr[i] <= pivot <= arr[j]; where, i < pivot and j > pivot
*/

int hPartition(int arr[], int l, int h)
{
    int pivot = arr[l]; // First element is taken as pivot in Hoares partition

    int i = l - 1, j = h + 1; // Here i will help in lHS partition and RHS partition j will  of array
    while (true)
    { // The do-while loop will increment i first, and then check codition

        // this do-while loop will give value of i, where arr[i] > pivot (element greater than pivot)
        do
        {
            i++;
        } while (arr[i] < pivot);

        // this do-while loop will give value of i, where arr[i] < pivot (element smaller than pivot)
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) // The case when LHS and RHS partition are done
        {
            return j;
        }

        // As, arr[i] > pivot and arr[j] < pivot. Hence, we will swap them
        swap(arr[i], arr[j]); // This swap will ensure that elements all smaller elements than pivot are in LHS of pivot and bigger elements than pivot in RHS of pivot
    }
}

int main()
{
    int a[] = {5, 3, 8, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "new pivot(index) is: " << hPartition(a, 0, n - 1) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}