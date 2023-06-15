/*
    I/P: 231*+9-
    O/P: -4

    I/P: 123+*8-
    O/P: -3
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
1.) Create Empty Stack
2.) Traverse through all the elements of given string. For each char x,
    - If x is operand, push it to stack
    - Else if 'x' is operator:
        -> int_val1 = st.top(); st.pop();
        -> int_val2 = st.top(); st.pop();
        -> Compute int_val2 'x' int_val1 => And push the result to stack
        Finally, when stack size == 1 => return st.top()
*/
int evaluatePostfix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
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
                res = val2 + val1;
                break;
            case '-':
                res = val2 - val1;
                break;
            case '*':
                res = val2 * val1;
                break;
            case '/':
                res = val2 / val1;
                break;
            }

            st.push(res);
        }
    }

    return st.top();
}

int main()
{
    string exp = "231*+9-";
    Evaluate obj(exp.length());
    cout << "Postfix evaluation: " << obj.evaluatePostfix(exp) << endl;
    return 0;
}
