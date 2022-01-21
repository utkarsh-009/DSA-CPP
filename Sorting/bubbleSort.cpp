#include <iostream>
using namespace std;

//Selection Sort function: Takes input array and size of array
void bubbleSort(int arr[], int n)
{
    bool swapped; //this swapped boolean will be used to check if array is sorted or unsorted
    for (int i = 0; i < n; i++) 
    {
        // Initially before performing pass swapped is assigned as false
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) //NOTE: we will run the loop until j = n - i - 1 , To avoid reductant passes
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true; //  if swap takes place we will set its value as true
            }
        }
        if (swapped == false) // if swap does'nt takes place in the pass, it means that array has been sorted
        {
            break; // as array is sorted, we will break the loop
        }
    }
}

int main()
{
    int a[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(a) / sizeof(a[0]); // Size of array is calculated in this manner
    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}