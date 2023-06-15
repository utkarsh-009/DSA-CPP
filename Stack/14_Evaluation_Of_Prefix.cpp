/*
    I/P: +*123
    O/P: 5 (1*2+3 => 2+3 = 5)
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
1.) Create Empty Stack
2.) Traverse through all the elements of given string from right to left. For each char x,
    - If x is operand, push it to stack
    - Else if 'x' is operator:
        -> int_val1 = st.top(); st.pop();
        -> int_val2 = st.top(); st.pop();
        -> Compute int_val1 'x' int_val2 => And push the result to stack
        Finally, when stack size == 1 => return st.top()
*/
int evaluatePrefix(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int val1 = st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            int res = 0;
            switch (c)
            {
            case '+':
                res = val1 + val2;
                break;
            case '-':
                res = val1 - val2;
                break;
            case '*':
                res = val1 * val2;
                break;
            case '/':
                res = val1 / val2;
                break;
            }

            st.push(res);
        }
    }

    return st.top();
}

int main()
{
    string exp = "+*123";
    cout << "Postfix evaluation: " << evaluatePrefix(exp) << endl;
    return 0;
}
