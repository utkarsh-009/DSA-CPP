#include <iostream>
using namespace std;

//Bubble Sort function: Takes input array and size of array
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_ind] > arr[j])
            {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
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