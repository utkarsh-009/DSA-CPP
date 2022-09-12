/*
Given weights and values of N items,
we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Input:
    N = 3, W = 50
    values[] = {60,100,120}
    weight[] = {10,20,30}
Output: 240.00
Explanation: Total maximum value of item we can have is 240.00 from the given capacity of sack.

Input:
    N = 2, W = 50
    values[] = {60,100}
    weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item. We can have is 160.00 from the given capacity of sack.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
    Item(int v, int w)
    {
        value = v;
        weight = w;
    }
};

// Using Greedy Approach [TC: O(nlogn), AS: O(1)]
static bool myCmp(Item item1, Item item2) // Sorting in decreasing order of ratio (value/weight)
{
    return (double)item1.value / item1.weight > (double)item2.value / item2.weight;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, myCmp); // Sorting in decreasing order of ratio (value/weight) using myCmp custom comparator

    double max_val = 0; // maximum value in knapsack
    for (int i = 0; i < n && W > 0; i++)
    {
        double val = arr[i].value;
        double wt = arr[i].weight;

        if (wt < W) // Complete
        {
            // Item weight less than current capacity => Include it into max_val and update current capacity
            max_val += val;
            W -= wt;
        }

        else // Partial
        {
            // if current capacity not enough to take complete current items weight
            max_val += (val / wt) * W;
            W = 0;
        }
    }

    return max_val; // Returning the maximum possible value that can be stored in fractional knapsack
}

int main()
{
    Item i1(60, 10), i2(100, 20), i3(120, 30);
    Item arr[] = {i1, i2, i3};

    int n = 3, W = 50;

    cout << fractionalKnapsack(W, arr, n);

    return 0;
}