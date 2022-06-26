#include <iostream>
using namespace std;

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

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = hPartition(arr, l, h); // returns a pivot around which partition is done
        quickSort(arr, l, p - 1);      // Recursievly quickSorting LHS
        quickSort(arr, p + 1, h);      // Recursievly quickSorting RHS
    }
}

int main()
{
    int a[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(a) / sizeof(a[0]); // Size of array is calculated in this manner
    quickSort(a, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}