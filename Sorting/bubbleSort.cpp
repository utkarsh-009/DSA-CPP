#include <iostream>
using namespace std;

//Selection Sort function: Takes input array and size of array
void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int a[] = {23, 56, 32, 775, 23, 775, 3, 1000, 64};

    int n = sizeof(a) / sizeof(a[0]);// Size of array is calculated in this manner
    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}