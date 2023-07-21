/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
After each operation, the count will start from k+1th person. The task is to choose the safe place in the circle so that when you perform these operations
starting from 1st place in the circle, you are the last one remaining and survive.

Input: n = 3, k = 2
Output: 3
Explanation: There are 3 persons so skipping 1 person i.e 1st person 2nd
person will be killed. Thus the safe position is 3.
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), AS: O(N)
/*
Recursive Formula: generalJose(n - 1, k) + k) % n:
- Note as no of alive person after every recusive call will decrease by 1 => n-1 alive person in next round
- k remains same in every recursive call as it means kth person to be killed => k remains same in next round
- IMPORTANT:
    -> As after killing (k-1)th person (because of 0-based indexing) in round1 => we start round from kth person i.e. labelled as 0
    -> But note that we are calling general recursive call (n-1,k) that considers kth person as 0.
    Hence, we add k in every recursive call => ((n-1,k)+k) => 0->k, 1->k+1, 2->k+2,... i->k+i.
    -> NOTE: Overflow can occur, i.e. k + i can be greater than n => Hence, we use %n.
    -> Final recurrence formula: (n - 1, k) + k) % n:
NOTE: In general josephus indexing we use 0 based indexing.
*/
int generalJose(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }

    return (generalJose(n - 1, k) + k) % n;
}

// For 1 based Indexing we add 1
int josephus(int n, int k)
{
    return generalJose(n, k) + 1;
}