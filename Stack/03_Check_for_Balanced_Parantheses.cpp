/*
    I/P: ([{}]) or {}[()]
    O/P: Yes

    I/P: ((()) or ([)]
    O/P: No
*/

#include <bits/stdc++.h>
using namespace std;

// For only one type of parantheses [TC: O(n), AS: O(1)]
/*
Intution:
Parantheses Unbalanced when:
    1.) No of closing parantheses > No of opening parantheses (cnt < 0)
    2.) No of opening parantheses != No of closing parantheses (cnt != 0)
*/
bool isBalancedM1(string &s)
{
    bool flag = true;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') // counting no of opening parantheses
        {
            cnt++;
        }
        else // counting no of closing parantheses
        {
            cnt--;
        }

        if (cnt < 0) // no of closing parantheses > no of opening parantheses
        {
            flag = false;
            break;
        }
    }

    if (cnt != 0) // no of opening parantheses != no of closing parantheses
    {
        flag = false;
    }

    return flag;
}

// Using Stacks for multiple type of parantheses [TC: O(n), AS: O(n)]
/*
Intution:
    -> isMatching function to check balancing pairs or not
    -> Pushing Opening Parantheses in Stack
       NOTE: If we push closing parantheses in empty stack => Not Balanced
             If top of stack and the closing paranthese are not matching => Not Balanced
             Else we pop the top
*/
bool isMatching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool isBalancedM2(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char x = s[i];
        // Opening Parantheses
        if (x == '(' || x == '[' || x == '{')
        {
            st.push(x);
        }

        else // Closing Parantheses
        {
            if (st.empty() == true) // If we push closing parantheses in empty stack
            {
                return false;
            }

            else if (isMatching(st.top(), x) == false) // If top of stack and the closing paranthese are not matching
            {
                return false;
            }

            else
            {
                st.pop();
            }
        }
    }

    return (st.empty() == true);
}

int main()
{
    string str1 = "((()))", str2 = "([{}])";

    ((isBalancedM1(str1)) ? cout << "Yes" : cout << "No");
    cout << endl;
    ((isBalancedM2(str2)) ? cout << "Yes" : cout << "No");
}
