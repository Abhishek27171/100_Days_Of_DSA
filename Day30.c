/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// create polynomial
struct Node *createPoly(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        scanf("%d %d", &newNode->coeff, &newNode->exp);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// print polynomial
void printPoly(struct Node *head)
{
    while (head != NULL)
    {
        if (head->exp == 0)
            printf("%d", head->coeff);

        else if (head->exp == 1)
            printf("%dx", head->coeff);

        else
            printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    struct Node *poly = createPoly(n);

    printPoly(poly);

    return 0;
}