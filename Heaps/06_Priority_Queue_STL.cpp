/*
    Priority Queue in C++ STL: Implemented Using Heap
    top(): O(1)
    empty(): O(1)
    size(): O(1)

    pop(): O(logn)
    push(): O(logn)
*/

#include <iostream>
#include <queue>
using namespace std;

// In priority queue STL, the default priority queue that we create is always a Max Heap => Maximum Element At Top
// For Descending Order
void note1()
{
    // Max Heap: Maximum Element At Top
    priority_queue<int> pq;

    // Push Operation
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(12);

    // size() and top() operations
    cout << "Size of Priority Queue: " << pq.size() << endl;
    cout << "Top of Priority Queue: " << pq.top() << endl;

    cout << "Printing top items one-by-one: ";
    // empty() and pop() operations
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

// For Ascending Order
void note2()
{
    // Min Heap: Minimum Element At Top
    priority_queue<int, vector<int>, greater<int>> pq;
    // NOTE: vector is underlying container used to implement priority queue and not arrays. That's why we have vector<int> in the above syntax

    // Push Operation
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(12);

    // size() and top() operations
    cout << "Size of Priority Queue: " << pq.size() << endl;
    cout << "Top of Priority Queue: " << pq.top() << endl;

    cout << "Printing top items one-by-one: ";

    // empty() and pop() operations
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

// IMP NOTE
void note3()
{

    int arr[] = {10, 15, 5, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Max Heap: Maximum Element At Top
    priority_queue<int> pq(arr, arr + n);
    /*
    NOTE:
        The constuctor method priority_queue<int> pq(arr, arr + n); is much more efficient than pushing elements one by one because the function
        directly calls the build heap method giving O(n) time comp. whereas in the push operation we have to everytime maintain the heap property after
        every operations
    */

    // size() and top() operations
    cout << "Size of Priority Queue: " << pq.size() << endl;
    cout << "Top of Priority Queue: " << pq.top() << endl;

    cout << "Printing top items one-by-one: ";
    // empty() and pop() operations
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

// IMP Trick: To get min heap using max heap and also to avoid remebering complex syntax of min heap
void note4()
{
    int arr[] = {10, 15, 5, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) // Multiplying all array elements by -1;
    {
        arr[i] = -1 * arr[i];
    }

    priority_queue<int> pq(arr, arr + n);

    // size() and top() operations
    cout << "Size of Priority Queue: " << pq.size() << endl;
    cout << "Top of Priority Queue: " << -pq.top() << endl; // -pq.top() inorder to get actual element of array

    cout << "Printing top items one-by-one: ";
    // empty() and pop() operations
    while (pq.empty() == false)
    {
        cout << -pq.top() << " "; // -pq.top() inorder to get actual element of array
        pq.pop();
    }
}

int main()
{
    note1();
    cout << "\n\n";

    note2();
    cout << "\n\n";

    note3();
    cout << "\n\n";

    note4();
    cout << "\n\n";
}
