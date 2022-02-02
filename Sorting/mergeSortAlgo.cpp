#include <bits/stdc++.h>
using namespace std;

//merge function to merge two sorted sub arrays into whole sorted array
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2]; //Creating two arrays left and right

    //Size of left array will be, n1 = mid - low + 1;
    //Size of right array will be, n2 = high - (mid + 1) - 1 = high - mid;

    //Copying elements of original array into left and right arrays
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + low];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[i + mid + 1];
    }

    //Now we will be comparing these two sorted sub arrays and finally merging them in as whole sorted array
    int i = 0, j = 0, k = low;
    //Running while loop until one of the sorted sub array merges into original array in sorted order
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) //Comparing elements of right and left sub arrays and placing them in original array in whole sorted manner
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    //Now merging the sorted sub array whose elements are not completely merged inside whole sorted array
    //As these sub arrays are already sorted, we will directly place them in whole sorted array
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        arr[k] = right[i];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l) //Atleast 2 elements required to use mergeSort function, as l = r => size of element is 1
    {
        int m = l + (r - l) / 2; // This variable stores middle value of the array
        //This m is written as l+(r-l)/2 instead of (r+l)/2, inorder to avoid overflow

        mergeSort(arr, l, m);     //Recursively sorting left sub array
        mergeSort(arr, m + 1, r); //Recursively sorting right sub array
        merge(arr, l, m, r);      //Merging these two arrays using merge function, to finally get whole sorted array
    }
}

int main()
{
    //merge function
    int a[] = {5, 8, 12, 14, 7};
    merge(a, 0, 3, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    //merge sort function
    int arr[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(arr) / sizeof(arr[0]); // Size of array is calculated in this manner
    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}