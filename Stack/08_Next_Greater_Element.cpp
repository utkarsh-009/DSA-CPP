/*
The Next greater Element for an element x is the first greater element on the right side of x in the array.
Elements for which no greater element exist, consider the next greater element as -1.
    Input: arr[] = [ 4 , 5 , 2 , 25 ]
    Output:          5   25  25  -1
    Explanation: except 25 every element has an element greater than them present on the right side

    Input: arr[] = [ 13 , 7, 6 , 12 ]
    Output:         -1   12  12  -1
    Explanation: 13 and 12 don’t have any element greater than them present on the right side
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*n), AS: O(1)]
void printNextGreaterNaive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        bool nextFound = false;

        for (int j = i + 1; j < n; j++)
        {
            int next = arr[j];
            if (curr < next)
            {
                cout << next << " ";
                nextFound = true;
                break;
            }
        }

        if (nextFound == false)
        {
            cout << -1 << " ";
        }
    }
}

// Efficient [TC: O(n), AS: O(n)]
/*
Intution: => Next Greater Element (i = 0 to i = n-1) == Previous Greater Element (i = n-1 to i = 0)
Keep popping the element unless:
Iterate from i = n-1 to i = 0
    1.) We get a top that is greater than arr[i] or
    2.) Stack becomes empty
Note: Don't forget to push arr[i] later in the stack
*/
void printNextGreaterEff(int arr[], int n)
{
    vector<int> ans(n);

    stack<int> s;

    s.push(arr[n - 1]);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }

        else
        {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int x : ans)
    {
        cout << x << " ";
    }
}

int main()
{
    int arr[] = {4, 5, 2, 25}, n = 4;
    printNextGreaterEff(arr, n);
}
