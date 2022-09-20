/*
Implement Two stacks in a single array.
*/

#include <bits/stdc++.h>
using namespace std;

// SPACE EFFICIENT [TC: O(n), AS: O(n)] => all operations O(1)
/*
Keep one stack's top in one end and other stack's end at other end: top1 = -1 and top2 = cap
*/
struct TwoStacks
{
    int *arr; // Single Array
    int cap;
    int top1, top2;

    TwoStacks(int c)
    {
        cap = c;
        arr = new int[c];
        top1 = -1;
        top2 = cap;
    }

    void push1(int x) // top1++
    {
        if (top1 + 1 < top2)
        {
            top1++;
            arr[top1] = x;
        }

        else
        {
            cout << "Stack1 Overflow" << endl;
        }
    }

    void push2(int x) // top2--;
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }

        else
        {
            cout << "Stack2 Overflow" << endl;
        }
    }

    int pop1() // top1--;
    {
        if (top1 >= 0)
        {
            int temp = arr[top1];
            top1--;
            return temp;
        }

        else
        {
            cout << "Stack1 Underflow" << endl;
            return -1;
        }
    }

    int pop2() // top2++;
    {
        if (top2 < cap)
        {
            int temp = arr[top2];
            top2++;
            return temp;
        }
        else
        {
            cout << "Stack2 Underflow" << endl;
            return -1;
        }
    }
};

int main()
{
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}
