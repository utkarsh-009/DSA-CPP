/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
Assume that all bars have same width and the width is 1 unit.
    I/P: {6,2,5,4,1,5,6}
    O/P: 10 (Select 5 and 6 with h = 5, 5*2 = 10)

    I/P: {2,5,1}
    O/P: 5 (Select 5 alone, 5*1 = 5)
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), AS: O(N)
void findNextSmaller(long long arr[], int n, vector<long long> &nextSmaller)
{
    stack<long long> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ((st.empty()) ? nextSmaller[i] = n : nextSmaller[i] = st.top());
        st.push(i);
    }
}

void findPrevSmaller(long long arr[], int n, vector<long long> &prevSmaller)
{
    stack<long long> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ((st.empty()) ? prevSmaller[i] = -1 : prevSmaller[i] = st.top());

        st.push(i);
    }
}

long long getMaxArea(long long arr[], int n)
{
    vector<long long> nextSmaller(n);
    vector<long long> prevSmaller(n);

    findNextSmaller(arr, n, nextSmaller);
    findPrevSmaller(arr, n, prevSmaller);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long currArea = arr[i];
        long long leftArea = (nextSmaller[i] - i - 1) * arr[i];
        long long rightArea = (i - prevSmaller[i] - 1) * arr[i];
        long long totalArea = currArea + leftArea + rightArea;
        ans = max(ans, totalArea);
    }

    return ans;
}

int main()
{
    long long arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    cout << "Maximum Area: " << getMaxArea(arr, n);
    return 0;
}
