/*
    I/P: {10,20,30,40,50}
         {5,15,25,35,45}
    O/P: 27.5 ((25+30)/2{5,10,15,20,*25,30*,35,40,45,50})

Finding Median of Two Sorted Arrays
*/

#include <bits/stdc++.h>
using namespace std;

// Efficient: Using Binary Search [TC: O(logn1),AS:]
/*
->During binary search, we maintain two sets:
    Set1: Left Half SET: It will contain left side elements of arr1 and arr2  (arr1[0,....i1-1], arr2[0,...i2-1])
    Set2: Right Half SET: It will contain right side elements of arr1 and arr2 (arr1[i1,...n1-1], arr2[i2,....n2-1])
-> It will consists of exactly half number of elements in left side and right side
-> Let i1 in arr1 be index of beggining of set1 for right side and i2 in arr2 be index of be beginning of set2 for right side
-> i2 = (n1+n2+1)/2 - i1
-> NOTE: When half of the elements are in left half set and half of the elements in right half set.
        Then, median = (maximum of left half set + minimum of right half set)/2

**GOAL: mxl1 < mnr2 && mxl2 < mnr1** OR max1 <= min2 && max2 <= min1
arr1=  [...,mxl1, mnr1...] / [...,max1, min1...]
arr2=  [...,mxl2, mnr2...]/  [...,max2, min2...]

*/

double medianOf2SortedArrays(int a1[], int a2[], int n1, int n2) // n1 <= n2
{
    int begin1 = 0, end1 = n1;

    while (begin1 < end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];

        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            }
            else
            {
                return (double)max(max1, max2);
            }
        }
        else if (max1 > min2)
        {
            end1 = i1 - 1;
        }
        else
        {

            begin1 = i1 + 1;
        }
    }

    return -1;
}

int main()
{
    int a1[] = {10, 20, 30, 40, 50}, n1 = 5, a2[] = {5, 15, 25, 35, 45}, n2 = 5;

    cout << medianOf2SortedArrays(a1, a2, n1, n2);

    return 0;
}
