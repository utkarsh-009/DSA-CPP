/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.

Input:
    N = 4
    Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input:
    N = 5
    Jobs = {(1,2,100),(2,1,19),(3,2,27),S(4,1,25),(5,1,15)}
Output: 2 127
Explanation: 2 jobs can be done with maximum profit of 127 (100+27).
*/

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline

    Job(int i, int d, int p)
    {
        id = i;
        dead = d;
        profit = p;
    }
};

//  [TC: O(nlogn), AS: O(N)]
static bool myCmp(Job job1, Job job2) // To sort jobs on basis of decreasing profits
{
    return (job1.profit > job2.profit);
}

// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, myCmp); // Sorting jobs on basis of decreasing profits using custom comparator

    vector<int> jobs(n + 1, -1); // initialise jobs vector of size n+1 with -1
    // -1 indicates that slot is empty

    int max_profit = 0, no_of_jobs = 0;
    for (int i = 0; i < n; i++)
    {
        int job_id = arr[i].id;
        int deadline = arr[i].dead;
        int job_profit = arr[i].profit;

        // Putting the job at latest empty slot
        while (deadline)
        {
            if (jobs[deadline] == -1) // Latest empty slot found
            {
                jobs[deadline] = job_id; // Putting job into the slot

                max_profit += job_profit; // Adding its profit
                no_of_jobs++;             // Incrementing no of jobs

                break;
            }
            else
            {
                deadline--;
            }
        }
    }

    return {no_of_jobs, max_profit}; // Returing number of jobs done and the maximum profit
}
int main()
{
    Job j1(1, 4, 20), j2(2, 1, 10), j3(3, 1, 40), j4(4, 1, 30);

    Job arr[] = {j1, j2, j3, j4};
    int n = 4;

    for (auto x : JobScheduling(arr, n)) // To print number of jobs done and the maximum profit
    {
        cout << x << " ";
    }
}
