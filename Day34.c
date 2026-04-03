/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// push function
void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// pop function
int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node *temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// evaluate postfix
int evaluatePostfix(char exp[])
{
    struct Node *stack = NULL;
    int i = 0;

    while (exp[i] != '\0')
    {

        // skip spaces
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        // if operand
        if (isdigit(exp[i]))
        {
            int num = 0;

            // handle multi-digit numbers
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(&stack, num);
        }
        // operator
        else
        {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (exp[i])
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            }

            push(&stack, result);
            i++;
        }
    }

    return pop(&stack);
}

int main()
{
    char exp[100];

    // input postfix expression
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    // output result
    printf("%d", result);

    return 0;
}