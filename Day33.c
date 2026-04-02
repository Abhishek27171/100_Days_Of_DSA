/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char x)
{
    stack[++top] = x;
}

// pop function
char pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

// precedence function
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    // input infix expression
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        // if operand, add to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        // if '(' push to stack
        else if (ch == '(')
        {
            push(ch);
        }
        // if ')' pop until '('
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        // operator
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    // output postfix expression
    printf("%s", postfix);

    return 0;
}