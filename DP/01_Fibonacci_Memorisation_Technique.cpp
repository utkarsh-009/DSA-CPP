#include <iostream>
#include <vector>
using namespace std;
// MEMORIZATION TECHNIQUE (TOP DOWN APPROACH)
//  Time Complexity : O(n)
//  Space Complexity : O(n)
 
// Function to find Fibonacci Sequence using DP with Memorization Technique
int fiboDP(int n, vector<int> memo)
{
    if (memo[n] == -1) // Condition if the values has not been calculated earlier
    {
        int res;
        if (n == 0 || n == 1) // Base condition
        {
            res = n;
        }
        else // To find value of nth Fibonacci number recursievly
        {
            res = fiboDP(n - 1, memo) + fiboDP(n - 2, memo);
        }
        memo[n] = res; // storing the value of computed nth fibonacci number
    }
    return memo[n]; // returning the value of the nth fibonacci number
}
 
int main()
{
    vector<int> memo(100, -1); // initialising values of memory array as -1
    // This -1 indicates that this fibonacci number is not computed before
    memo[0] = 0;
 
    cout << fiboDP(10, memo); // number present at index 10 in fibonacci sequence
}