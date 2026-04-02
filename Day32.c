/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

#define MAX 100

int main()
{
    int stack[MAX];
    int top = -1;
    int n, m, i, x;

    // Input number of elements
    scanf("%d", &n);

    // Push elements into stack
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        stack[++top] = x;
    }

    // Number of pops
    scanf("%d", &m);

    // Pop m elements
    for (i = 0; i < m; i++)
    {
        if (top == -1)
        {
            break; // stack underflow (not required to print here)
        }
        top--;
    }

    // Print remaining stack from top to bottom
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}