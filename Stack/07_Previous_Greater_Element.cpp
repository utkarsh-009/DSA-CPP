/*
Given an array of distinct elements, find previous greater element for every element.
If previous greater element does not exist, print -1.

    Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
    Output :         -1, 10, 4, -1, -1, 40, 40

    Input : arr[] = {10, 20, 30, 40}
    Output :        -1, -1, -1, -1

    Input : arr[] = {40, 30, 20, 10}
    Output :        -1, 40, 30, 20
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*n), AS: O(1)]
void printPrevGreaterNaive(int arr[], int n)
{
    if (n >= 1)
    {
        cout << -1 << " ";
    }

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        bool prevFound = false;
        for (int j = i - 1; j >= 0; j--)
        {
            int prev = arr[j];
            if (prev > curr)
            {
                cout << prev << " ";
                prevFound = true;
                break;
            }
        }

        if (prevFound == false)
        {
            cout << -1 << " ";
        }
    }
}

// Efficient: Using Stacks [TC: O(n), AS: O(n)]
/*
Intution: Keep popping the element unless:
1.) We get a top that is greater than arr[i] or
2.) Stack becomes empty
Note: Don't forget to push arr[i] later in the stack
*/
void printPrevGreaterEff(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);

    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top() <= arr[i]) //
        {
            s.pop();
        }

        if (s.empty())
        {
            cout << -1 << " ";
        }

        else
        {
            cout << s.top() << " ";
        }
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {10, 4, 2, 20, 40, 12, 30}, n = 7;
    printPrevGreaterEff(arr, n);
}
