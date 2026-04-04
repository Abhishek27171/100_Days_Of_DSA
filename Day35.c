/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Display queue elements
void display()
{
    struct node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    display();

    return 0;
}