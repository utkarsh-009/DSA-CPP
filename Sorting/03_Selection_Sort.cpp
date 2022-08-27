#include <iostream>
using namespace std;

//Bubble Sort function: Takes input array and size of array
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //Initially assign index 0 as min_ind
        int min_ind = i; //min_ind is a variable which will store index of minimum value element

        for (int j = i + 1; j < n; j++) // Loop to get actual min_ind value from array
        {
            if (arr[min_ind] > arr[j]) // Updating index of the min_ind, if we get lower value element
            {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]); // Swapping of the element with min_ind element
    }
}

int main()
{
    int a[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(a) / sizeof(a[0]); // Size of array is calculated in this manner
    selectionSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}