/*
    I/P: a+b*(c^d-e)^(f+g*h)-i
    O/P: abcd^e-fgh*+^*+i-

    I/P: a+b/c-d*e
    O/P: abc/+de*-
*/

#include <bits/stdc++.h>
using namespace std;

//  [TC: O(n), AS: O(n)]
/*
Intution: Using stack to store operators and using its precendence we convert infix to postfix
Approach:
1. Create an Empty Stack
2. Do following for every character x from left to right:
If x is:
    - Operand: Print it as it is
    - Left Parantheses: Push it to stack
    - Right Parantheses: Pop and print all the characters until left paranthese if found
    - Operator:
        i.) If stack is empty, push it to stack
        ii.) Else, compare it with top
            -> Higher Precedence than stack's top => Push it to stack
            -> Lower Precedence than stack's top => Pop and print all the characters until the current operator becomes the
            higher precendence or until stack becomes empty. (When higher precendence found/ stack becomes empty) => Push it to stack
            -> Equal Precedence: We use associativity to decide the high precedence operator
    - Now after iterating from all characters, if there are any character remaining in stack => We print them all
*/

class ConvertInfixToPostfix
{
private:
    int top;
    int capacity;
    char *arr;
    string output;
    map<int, int> precedence;

public:
    ConvertInfixToPostfix(int capacity)
    {
        top = -1;
        this->capacity = capacity;
        arr = new char[capacity];
        output = "";
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['^'] = 3;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    char peek()
    {
        if (isEmpty())
        {
            return '$';
        }
        return arr[top];
    }

    char pop()
    {
        if (isEmpty())
        {
            return '$';
        }

        return arr[top--];
    }

    void push(char x)
    {
        if (top == capacity - 1)
        {
            return;
        }

        arr[++top] = x;
    }

    bool isOperand(char x)
    {
        return isalpha(x);
    }

    bool notGreater(char i)
    {
        // The precendence order of ith character
        auto a = precedence.find(i);

        // The precedence order of top of the element of stack
        auto b = precedence.find(peek());

        // If both characters are present in precedence map
        if (a != precedence.end() && b != precedence.end())
        {
            // return true, if current character has lower than or equal to precedence.
            // Implying that the current character has lower precedence than stack's top
            return (a->second <= b->second);
        }

        return false;
    }

    void infixToPostfix(string exp)
    {
        for (int i = 0; i < exp.length(); i++)
        {
            // Operand => Append it to O/P
            if (isOperand(exp[i]))
            {
                output += exp[i];
            }
            // Left Bracket => Push onto stack
            else if (exp[i] == '(')
            {
                push(exp[i]);
            }
            // Right Bracket => Pop from stack and append it O/P unitl we get top as '('
            else if (exp[i] == ')')
            {
                while (!isEmpty() && peek() != '(')
                {
                    char a = pop();
                    output += a;
                }
                if (!isEmpty() && peek() != '(')
                {
                    cout << "Invalid expression" << endl;
                    return;
                }
                else
                {
                    pop();
                }
            }
            /*
            Else if current operator is of:
                1.) Higher Precedence => Push it to stack
                2.) Lower Precedence => Pop all the elements in stack until
                we find that current operator becomes higher precedence or until stack is empty
            At the end, we push the current operator to stack.
            */
            else
            {
                while (!isEmpty() && notGreater(exp[i]))
                {
                    char a = pop();
                    output += a;
                }
                push(exp[i]);
            }
        }

        // Lastly, Pop all the remaining elements from stack
        while (!isEmpty())
        {
            char a = pop();
            output += a;
        }
        cout << output << endl;
    }
};

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    ConvertInfixToPostfix obj(exp.length());
    obj.infixToPostfix(exp);
    return 0;
}
