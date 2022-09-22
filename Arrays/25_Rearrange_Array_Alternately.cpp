/*
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e
first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
    Input: N = 6, arr[] = {1,2,3,4,5,6}
    Output: 6 1 5 2 4 3
    Explanation: Max element = 6, min = 1,
    second max = 5, second min = 2, and
    so on... Modified array is : 6 1 5 2 4 3.

    Input: N = 11, arr[]={10,20,30,40,50,60,70,80,90,100,110}
    Output: 110 10 100 20 90 30 80 40 70 50 60
*/

#include <bits/stdc++.h>
using namespace std;

// Using Auxillary Array [TC: O(n), AS: O(n)]
void rearrangeNaive(int arr[], int n)
{

    // Your code here
    vector<long long> aux(n);
    int low = 0, high = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            aux[i] = arr[high];
            high--;
        }
        else
        {
            aux[i] = arr[low];
            low++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = aux[i];
    }
}
// Space Optimised [TC: O(n), AS: O(1)]
/*
Using the expression:
  arr[i] += (arr[max_idx] % max_element) * max_element;
  arr[i] = arr[i]/max_element
*/
void rearrange(int arr[], int n)
{

    // Your code here
    int max_element = arr[n - 1] + 1;
    int max_idx = n - 1, min_idx = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[max_idx] % max_element) * max_element;
            max_idx--;
        }
        else
        {
            arr[i] += (arr[min_idx] % max_element) * max_element;
            min_idx++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / max_element;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    rearrange(arr, n);

    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
