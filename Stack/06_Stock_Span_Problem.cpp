/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and
we need to calculate the span of stocks price for all n days.The span Si of the stocks price on a given day i is defined as
**The maximum number of consecutive days just before the given day, for which the price of the stock
on the current day is less than or equal to its price on the given day.**

    Input:
    N = 7, price[] = [100 80 60 70 60 75 85]
    Output:
    1 1 1 2 1 4 6

    Input:
    N = 6, price[] = [10 4 5 90 120 80]
    Output:
    1 1 2 4 5 1
*/

#include <bits/stdc++.h>
using namespace std;

// Naive [TC: O(n*n), AS: O(1)]
vector<int> calculateSpanNaive(int price[], int n)
{
    vector<int> span;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x = price[i];
        int j = i;
        while (j >= 0)
        {

            if (price[j] <= x)
            {
                cnt++;
                j--;
            }
            else
            {
                break;
            }
        }
        span.push_back(cnt);
        cnt = 0;
    }

    return span;
}

// Efficient Using Stack [TC: O(n), AS: O(n)]
/*
Intution:
The span on day i can be easily computed if we know the closest day preceding i, such that the price is greater
than on that day than the price on day i.
We will pop day index from stack unless and until, one of these two conditions occur where 1.) stack becomes empty, 2.) price[s.top()] > price[i]
1.) If such a day exists where for the closest day preceding i that price is greater than on that day than the price on day i. =>  span[i] = i - s.top();
2.) If such day does not exist => span[i] = i+1;
3.) Then we push day i value in stack
*/
vector<int> calculateSpanEff(int price[], int n)
{
    vector<int> span(n);

    stack<int> s; // Stack Will Store Index (Day Number from 0 to N-1)

    // Initally pushing day 0 into the stack and it's span will be 1
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && price[s.top()] <= price[i]) // We will keep poping from stack if top of stack (day index) is having price less than the ith day price
        {
            s.pop();
        }

        if (s.empty()) // if stack is empty => All elements in stack where having price less than the ith day price
        {
            span[i] = i + 1; // total days including the day itself => i + 1 (as i is 0-based index)
        }

        else // if stack is not empty => Some day less than i has higher price than ith day
        {
            span[i] = i - s.top(); // [i+1 - (s.top()+1)] days => i - s.top() [As Differnce betw two no's remain same when both increamented by same value]
        }

        s.push(i); // Pushing ith day index into stack
    }

    return span;
}

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85}, N = 7;
    for (int x : calculateSpanEff(price, N))
    {
        cout << x << " ";
    }
}
