/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream
formed by each insertion of X to the new stream.

    Input: N = 4, X[] = 5,15,1,3
    Output: 5 10 5 4
    Explanation:Flow in stream : 5, 15, 1, 3
    5 goes to stream --> median 5 (5)
    15 goes to stream --> median 10 (5,15)
    1 goes to stream --> median 5 (5,15,1)
    3 goes to stream --> median 4 (5,15,1 3)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to insert heap.
    priority_queue<double> mxHeap;                                  // stores 1st element of med
    priority_queue<double, vector<double>, greater<double>> mnHeap; // stores 2nd element of med

    void insertHeap(int &x)
    {
        if (mxHeap.size() == 0 || mxHeap.top() > x)
        {
            mxHeap.push(x);
        }
        else
        {
            mnHeap.push(x);
        }

        balanceHeaps();
    }

    void balanceHeaps()
    {
        if (mxHeap.size() > mnHeap.size() + 1)
        {
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        else if (mnHeap.size() > mxHeap.size())
        {
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }

    double getMedian()
    {
        int mxSz = mxHeap.size(), mnSz = mnHeap.size();
        double res = 0;
        if (mxSz == mnSz)
            res = (mnHeap.top() + mxHeap.top()) / 2.0;
        else
            res = mxHeap.top();

        return res;
    }
};