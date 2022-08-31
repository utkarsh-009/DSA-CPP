/*
    Input:
    N = 4
    array[] = {1,2,1,3,4,3}
    Output: 1 3

    Input:
    N = 2
    array[] = {1,2,2,1}
    Output: 2 1

Range of Element => 0 <= max(arr) <= n, n+2 = size of array
Two Element repeats, FIND THE REPEATING ELEMENT with MODIFICATION OF INPUT ARRAY ALLOWED
*/

#include <bits/stdc++.h>
using namespace std;

// No Auxillary Space required + Modification of input array allowed [TC: O(n),AS: O(1)]
vector<int> twoRepeated(int a[], int n)
{
    vector<int> res(2);
    bool first = false;

    // iterating over the array elements.
    for (int i = 0; i < n + 2; i++)
    {
        // making the visited elements negative.
        if (a[abs(a[i])] > 0)
            a[abs(a[i])] = -a[abs(a[i])];

        // if the number is negative, it was visited previously
        // so this would be the repeated element.
        else
        {
            // storing first and second repeated element accordingly.
            if (first == false)
            {
                res[0] = abs(a[i]);
                first = true;
            }
            else
            {
                res[1] = abs(a[i]);
                break;
            }
        }
    }
    // returning the result.
    return res;
}

int main()
{

    int arr[] = {1, 2, 1, 3, 4, 3}, n = 4;

    for (int x : twoRepeated(arr, n))
    {
        cout << x << " ";
    }

    return 0;
}