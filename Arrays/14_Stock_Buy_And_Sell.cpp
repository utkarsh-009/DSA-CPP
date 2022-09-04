/*
We know stock price for upcoming days. We want to maximise the profit.
Constraint: We can buy only one stock and cannot buy another unless we sell that only stock

    I/P: {1, 5, 3, 8, 12}
    O/P: 13 ({1,5}, {3,12} => 4  + 9 = 13)

    I/P: {30, 20, 10}
    O/P: 0 (Dont buy stock at all)
*/

#include <bits/stdc++.h>
using namespace std;

// Naive  [TC: O(n*n), AS: O(1)]
int maxProfitNaive(int price[], int start, int end)
{
    if (end <= start) // Base Case for Recursion
    {
        return 0;
    }

    int max_profit = 0;

    for (int i = start; i < end; i++) // arr[i] => The ith day we will buy the stock for arr[i]th price
    {
        for (int j = i + 1; j <= end; j++) // arr[j] => The jth day we will sell the stock for arr[j]th price
        {
            if (price[j] > price[i]) // The Day when, Sell Price > Buy Price
            {
                int curr_profit = (price[j] - price[i]) + maxProfitNaive(price, start, i - 1) + maxProfitNaive(price, j + 1, end);
                // maxProfitNaive(price, start, i - 1) => Now recursively looking for the ideal Buy-Sell Day on LHS
                // maxProfitNaive(price, j + 1, end)  => Now recursively looking for the ideal Buy-Sell Day on RHS
                max_profit = max(max_profit, curr_profit);
            }
        }
    }

    return max_profit;
}

// Efficient [TC: O(n), AS: O(1)]
/*
Approach: We will keep adding the profit  as price goes up unltil maxima (peak)
As soon it reaches maxima ((peak)) and price starts to move down, we will stop buying
*/
int maxProfit(int price[], int n)
{
    int max_profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1]) // buying and selling on each consecutive day where, price[i] > price[i-1]
        {
            max_profit += price[i] - price[i - 1];
        }
    }

    return max_profit;
}

int main()
{
    int price[] = {1, 5, 3, 8, 12}, n = 5;

    cout << maxProfit(price, n);
}
