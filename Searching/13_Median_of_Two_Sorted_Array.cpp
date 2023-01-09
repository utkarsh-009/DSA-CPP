/*
    I/P: {10,20,30,40,50}
         {5,15,25,35,45}
    O/P: 27.5 ((25+30)/2{5,10,15,20,*25,30*,35,40,45,50})

Finding Median of Two Sorted Arrays
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient: Using Binary Search [TC: O(logn1), AS: O(1)]
/*
->During binary search, we maintain two sets:
    Set1: Left Half SET: It will contain left side elements of arr1 and arr2  (arr1[0,....i1-1], arr2[0,...i2-1])
    Set2: Right Half SET: It will contain right side elements of arr1 and arr2 (arr1[i1,...n1-1], arr2[i2,....n2-1])
-> We have to make size of these two sets equal with (l1 <= r2 && l2 <= r1)
-> l1,l2,r1,r2
    l1 = maximum of arr1 in left set
    l2 = maximum of arr2 in left set
    r1 = minimum of arr1 in right set
    r2 = minimum of arr2 in right set
-> Here, cut1 and cut2 divides arr1 and arr2 such that:
l1 = arr[cut1-1], r1 = arr[cut1] & l2 = arr[cut2-1], r2 = arr[cut2-1]
Ex:
arr1[] = {1,3,4,7,10,12}
arr2[] = {2,3,6,15}
cut1 = 3; l1 = 2, r1 = 3 => {[1,3,4],[7,10,12]}
cut2 = 2; l2 = 1, r2 = 2 => {[2,3],[6,15]}
1 2 3 3 4 | 6 7 10 12 15
-> We are searching cut1 and cut2 using binary search, such that: size of these two sets equal with (l1 <= r2 && l2 <= r1)
-> It will consists of exactly half number of elements in left side and right side
-> Let cut1 in arr1 be index of beggining of set1 for right side and cut2 in arr2 be index of be beginning of set2 for right side
-> cut2 = medPos - i1. here, medPos = (n1+n2+1)/2
-> NOTE: When half of the elements are in left half set and half of the elements in right half set.
        Then, median = (maximum of left half set + minimum of right half set)/2

**GOAL: (l1 <= r2 && l2 <= r1)

*/

float median(int arr1[], int arr2[], int m, int n)
{
    if (m > n)
        return median(arr2, arr1, n, m); // ensuring that binary search happens on minimum size array

    int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
    while (low <= high)
    {
        // cut1 =>
        int cut1 = (low + high) >> 1;
        int cut2 = medianPos - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}

int main()
{
    int a1[] = {10, 20, 30, 40, 50}, n1 = 5, a2[] = {5, 15, 25, 35, 45}, n2 = 5;

    cout << median(a1, a2, n1, n2);

    return 0;
}
