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
/*
Note:
- When one element is repeated in the array it forms a cycle when graph of arr[i] is connected
- Example:
    arr[] = {1,3,2,4,6,5,7,3}
    graph = 1->3->4->6->7->3 (Cycle formed 3->4->6->7->3)
- As repeating element it at starting point of cycle, we can find the starting point by using slow and fast pointer

TPT: Using slow and fast pointer we can reach the starting point of cycle
Proof:
-> Proof1:
    - Proving both slow and fast pointers will reach destination exactly at same time
    - As we move slow pointer by 1 and fast pointer by 2. So,
        slow, fast => slow+1, fast+2 => slow+2, fast+4 =>...=> slow+n, fast+2n.
        Hence, they meet inside the cycle at some point 'x' distance from starting point of node
-> Proof2:
    - We need to prove that after reaching the meeting point of slow and fast pointer. If we shifted slow pointer to 0 and
    moved both fast and slow pointer by 1 => They will reach at the  starting point of cycle.
    - Let 'm' be distance from start(0) to starting point of chain length 'c'.
    - As fast distance moved twice as fast as slow pointer,
        Fast Dist = 2*(Slow Dist) => (m+x) + c*i = 2*(m+x) + c*j  =>  c*(i-2j) = m+x
        Hence, c*(i-2j) = m+x => (m+x) is a multiple of cycle length 'c'.
    - Now as, slow pointer is moved to start position and fast pointer is at meeting position.
    Hence, (Slow Dist till after m steps) => m => Starting point of cycle
           (Fast Dist after m steps) => (m+x+m)%c => m => Starting point of cycle
Hence, using slow and fast pointer we can reach the starting point of cycle.
*/
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
