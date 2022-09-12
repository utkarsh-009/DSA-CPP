/*
Given N activities with their start and finish day given in array start[ ] and end[ ].
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a given day.
    Input:
        N = 2
        start[] = {2, 1}
        end[] = {2, 2}
    Output: 1
    Explanation: A person can perform only one of the given activities.

    Input:
        N = 4
        start[] = {1, 3, 2, 5}
        end[] = {2, 4, 3, 6}
    Output: 3
    Explanation: A person can perform activities 1, 2 and 4.
*/

#include <bits/stdc++.h>
using namespace std;

// Greedy Approach [TC: O(nlogn), AS: O(1)]

bool myCmp(pair<int, int> a, pair<int, int> b) // Custom comparator sorts the pairs according to finish time in increasing order
{
    return (a.second < b.second);
}

int maxActivities(pair<int, int> act[], int n)
{
    sort(act, act + n, myCmp); // Sort Activites according to their finish times in increasing order

    int prev = 0; // This prev will keep track of index of previous activity picked
    int res = 1;  // Selecting the first activity

    for (int curr = 1; curr < n; curr++) // curr activity
    {
        if (act[curr].first >= act[prev].second) // Checking if curr and prev activities are overlapping or not
        {
            // If curr and prev activities not overlapping
            res++;       // Increment no of activities
            prev = curr; // Update prev index as curr
        }
    }

    return res; // Return the max activities that can be performed
}

int main()
{
    pair<int, int> act[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};

    int n = 3;
    cout << maxActivities(act, n);

    return 0;
}
