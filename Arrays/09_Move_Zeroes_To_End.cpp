/*
    I/P: arr[] = {3, 0, 8, 0, 12, 5, 6, 0}, n = 8
    O/P: {3, 8, 12, 5, 6, 0, 0, 0}

*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(1)]
void moveZeroesToEnd(int arr[], int n)
{

    int ind = 0; // To keep track of index of the leftmost zero element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            // NOTE: When no 0 is present at left, then the element swap its position with itself
            swap(arr[i], arr[ind]); // To swap element with leftmost 0
            ind++;
        }
    }
}

/*
Dry Run:
{10, 8, 0, 0, 12, 0} , n = 6

i = 0, ind = 0:
    arr[i] != 0 => swap(arr[i], arr[ind]), ind++, i++   ({10, 8, 0, 0, 12, 0})

i = 1, ind = 1:
    arr[i] != 0 => swap(arr[i], arr[ind]), ind++, i++   ({10, 8, 0, 0, 12, 0})

i = 2, ind = 2:
    arr[i] == 0 => i++      ({10, 8, 0, 0, 12, 0})

i = 3, ind = 2:
    arr[i] == 0 => i++      ({10, 8, 0, 0, 12, 0})

i = 4, ind = 2:
    arr[i] != 0 => swap(arr[i], arr[ind]), ind++, i++   ({10, 8, 12, 0, 0, 0})

i = 5, ind= 3:
    arr[i] == 0 => i++      ({10, 8, 12, 0, 0, 0})
*/

int main()
{
    int arr[] = {3, 0, 8, 0, 12, 5, 6, 0}, n = 8;

    cout << "Before Moving" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    moveZeroesToEnd(arr, n);
    cout << "\nAfter Moving" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
