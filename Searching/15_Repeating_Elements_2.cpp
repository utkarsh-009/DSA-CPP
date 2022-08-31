/*
    I/P: {4, 2, 1, 3, 2, 2}
    O/P: 2

    I/P: {1, 2, 3, 3, 4, 5}
    O/P: 3

Range of Element => 0 <= max(arr) <= n-1, n = size of array
Only One Element repeats, FIND THE REPEATING ELEMENT without MODIFICATION OF INPUT ARRAY
*/

#include <bits/stdc++.h>
using namespace std;

// No Auxillary Space required [TC: O(n),AS: O(1)]
int findRepeating(int arr[], int n) // Not for array, in which 0 is also present as SELF-LOOPS ARE FORMED
{
    int slow = arr[0], fast = arr[0];

    // Both pointer meet when difference of distance between them becomes equal to cycle length
    do // Assigning value in this manner, forms a loop if repeating element is present
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast); // Condition when both fast and slow pointer meet

    slow = arr[0]; // Moving slow pointer to begining (1st element)

    // Now moving both pointer at same speed
    while (slow != fast) // When slow and fast meet => Both points to repeating element
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

// For array, in which 0 is also present (SELF-LOOP removal)
int findRepeating0(int arr[], int n)
{
    int slow = arr[0] + 1, fast = arr[0] + 1;

    // Both pointer meet when difference of distance between them becomes equal to cycle length
    do // Assigning value in this manner, forms a loop if repeating element is present
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast); // Condition when both fast and slow pointer meet

    slow = arr[0] + 1; // Moving slow pointer to begining (1st element)

    // Now moving both pointer at same speed
    while (slow != fast) // When slow and fast meet => Both points to repeating element
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }

    return slow - 1;
}

int main()
{

    int arr1[] = {4, 2, 1, 3, 2, 2}, n1 = 6;
    int arr2[] = {0, 1, 2, 3, 4, 0}, n2 = 6;

    cout << findRepeating(arr1, n1) << endl;
    cout << findRepeating0(arr2, n2) << endl;
    return 0;
}
