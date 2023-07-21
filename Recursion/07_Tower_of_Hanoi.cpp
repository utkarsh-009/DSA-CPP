/*
In this Problem, we have to move all discs from A to C such that at any instance while moving disc,
the smaller disc should strictly be placed above larger disc.

    I/P: n = 1
    O/P: Move Disc1 frorm A to C

    I/P: n = 2
    O/P: Move Disc1 from A to B
         Move Disc2 from A to C
         Move Disc1 from B to C

    I/P: n = 3
    O/P: Move Disc1 from A to C
         Move Disc2 from A to B
         Move Disc1 from C to B
         Move Disc3 from A to C
         Move Disc1 from B to A
         Move Disc2 from B to C
         Move Disc1 from A to C

RULES:
->Only 1 Disc moves at a time
->NO LARGER DISC ABOVE SMALLER DISC
->Only the Disc at top of the tower can be moved
*/

#include <bits/stdc++.h>
using namespace std;

/*
GOAL:For we are moving disks from A to C. While taking into account of final goal from A to C, we can take A/B/C as auxillary tower
-> In this problem, we are basically moving (n-1) disc from source A to destination tower B using C as the auxillary tower.
-> The nth disc is moved from A to C.
-> Now, move (n-1) discs from source B to destination tower C taking A as the auxillary tower.

ALGORITHM: TOH(No of Disks, Source, Auxillary, Destination)

TOH(n, A, B, C)
->  TOH(n - 1, A, C, B)
->  Move nth disk from A to C
->  TOH(n-1, B, A, C)
*/

// Tower Of Hanoi [TC: O(2^n) ,AS: O(2^n)]
void TOH(int n, char A, char B, char C)
{
    if (n == 1) // Base Case;
    {
        cout << "Move Disc1 from " << A << " to " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);                                              // Move (n-1) Disks from A to B taking C as aux
    cout << "Move Disc" << n << " from " << A << " to " << C << endl; // Move nth Disk from A to C
    TOH(n - 1, B, A, C);                                              // Move (n-1) Disks from B to C taking A as aux
}

/*
// FOR BETTER UNDERSTANDING:

Standard Question (total no of moves required to move disks from source to destination):
-> Base Case: If there is only one disk (N==1), it is directly moved from the from rod to the
 to rod, and the function prints the corresponding move statement.
-> Otherwise: 
1.)The function recursively calls itself with N-1 disks, moving them from the
from source rod to the aux rod. The return value of this recursive call is added to count.
2.) After the recursive call, the function prints the move statement for moving the Nth disk
from the from rod to the to rod and increments the count by 1 as move is performed.
3.) Another recursive call is made with N-1 disks, moving them from the aux rod to the to
destination rod. The return value of this recursive call is stored in count2.
Finally, the function returns the sum of count1, count2, and 1 (representing the current move).

long long toh(int N, int from, int to, int aux) {
    long long count = 0;

    if(N == 1)
    {
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        count++;
        return count;
    }

    // Moving disk from src to aux
    count += toh(N-1, from, aux, to);

    // Printing the instruction and counting the move
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    count++;

    // Moving disk from aux to dst
    count += toh(N-1, aux, to, from);

    return count;
}

*/

int main()
{
    int n = 3;
    TOH(n, 'A', 'B', 'C');
    return 0;
}
